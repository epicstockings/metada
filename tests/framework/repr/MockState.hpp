#ifndef METADA_TESTS_FRAMEWORK_REPR_MOCK_STATE_HPP_
#define METADA_TESTS_FRAMEWORK_REPR_MOCK_STATE_HPP_

#include <gmock/gmock.h>

#include "IState.hpp"

namespace metada {
namespace framework {
namespace repr {
namespace tests {

class MockState : public IState {
 public:
  MOCK_METHOD(void, initialize, (), (override));
  MOCK_METHOD(void, reset, (), (override));
  MOCK_METHOD(void, validate, (), (const, override));

  MOCK_METHOD(void*, getData, (), (override));
  MOCK_METHOD(const void*, getData, (), (const, override));

  MOCK_METHOD(void, setMetadata,
              (const std::string& key, const std::string& value), (override));
  MOCK_METHOD(std::string, getMetadata, (const std::string& key),
              (const, override));

  MOCK_METHOD(const std::vector<std::string>&, getVariableNames, (),
              (const, override));
  MOCK_METHOD(const std::vector<size_t>&, getDimensions, (), (const, override));
};

}  // namespace tests
}  // namespace repr
}  // namespace framework
}  // namespace metada

#endif  // METADA_TESTS_FRAMEWORK_REPR_MOCK_STATE_HPP_