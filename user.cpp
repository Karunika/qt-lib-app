#include "user.h"

void from_json(const nlohmann::json& j, User& p) {
    j.at("user").get_to(p.user);
    j.at("pwd").get_to(p.pwd);
}

void to_json(nlohmann::json& j, const User& p) {
    j = nlohmann::json{
      {"user", p.user}, {"pwd", p.pwd}
    };
}
