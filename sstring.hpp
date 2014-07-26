#ifndef BYTEME_SSTRING_HPP_
#define BYTEME_SSTRING_HPP_

#include <vector>
#include <string>
#include <cstring>

#ifdef DEBUG
#include <cassert>
#endif

namespace byteme
{

/*
 * sstrings are NOT null terminated
 * constructors expect null terminated strings
 */
class sstring {

private:

    void encode(const char *from);

    void encode(const char *from, size_t length);

#ifdef DEBUG
    bool is_ascii(const char *from);
#endif

    inline bool is_alphanumeric(char c);

public:

    sstring();

    sstring(std::string from);

    sstring(const char *from);

    sstring(const char *from, size_t length);

    std::string decode();

    static std::string decode(const char *from, size_t length);

    ~sstring();

    size_t size();

    const char *data();

private:

    // TODO replace with char*
    std::vector<char> buf;

};

}

#endif // BYTEME_SSTRING_HPP_
