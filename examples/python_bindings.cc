#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <libcuckoo/cuckoohash_map.hh>

namespace py = pybind11;

PYBIND11_MODULE(pycuckoo, m) {
    py::class_<libcuckoo::cuckoohash_map<std::string, std::string>>(m, "CuckooHashMap")
        .def(py::init<>())
        .def("insert", [](libcuckoo::cuckoohash_map<std::string, std::string> &table, const py::bytes &key, const std::string &value) {
            table.insert(key, value);
        })
        .def("find", [](libcuckoo::cuckoohash_map<std::string, std::string> &table, const py::bytes &key) -> std::optional<std::string> {
            std::string value;
            if (table.find(key, value)) {
                return value;
            } else {
                return std::nullopt;
            }
        })
        .def("remove", [](libcuckoo::cuckoohash_map<std::string, std::string> &table, const py::bytes &key) -> std::optional<std::string> {
            try {
                std::string value = table.erase_and_return(key);
                return value;
            } catch (const std::out_of_range &) {
                return std::nullopt;
            }
        })
        .def("keys", [](libcuckoo::cuckoohash_map<std::string, std::string> &table) {
            auto lt = table.lock_table();
            std::vector<py::bytes> keys;
            for (const auto &item : lt) {
                keys.push_back(py::bytes(item.first));
            }
            return keys;
        });
}