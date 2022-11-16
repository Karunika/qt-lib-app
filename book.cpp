#include "book.h"

void from_json(const nlohmann::json& j, Book& b) {
    j.at("id").get_to(b.id);
    j.at("author").get_to(b.author);
    j.at("title").get_to(b.title);
    j.at("publisher").get_to(b.publisher);
    j.at("date").get_to(b.date);
    j.at("user").get_to(b.user);
    j.at("reserved").get_to(b.reserved);
    j.at("leased").get_to(b.leased);
}

void to_json(nlohmann::json& j, const Book& b) {
    j = nlohmann::json{
        {"id", b.id},
        {"author", b.author},
        {"title", b.title},
        {"publisher", b.publisher},
        {"date", b.date},
        {"user", b.user},
        {"reserved", b.reserved},
        {"leased", b.leased}
    };
}
