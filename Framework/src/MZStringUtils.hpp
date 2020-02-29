#include <algorithm> 
#include <cctype>
#include <locale>

// trim from start (in place)
static inline void ltrim(std::string& s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
    return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string& s) {
  s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
    return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s) {
  ltrim(s);
  rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
  ltrim(s);
  return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
  rtrim(s);
  return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
  trim(s);
  return s;
}

static inline std::string deduplicateWhitespaceToSpace(std::string s)// NSString* fixText(NSString* newText)
{
  std::string::iterator new_end = std::unique(s.begin(), s.end(),
    [&](const char& lhs, const char& rhs) {
      return (lhs == rhs) && ((lhs == ' ') || (lhs == '\t') || (lhs == '\n') || (lhs == '\v') || (lhs == '\f') || (lhs == '\r'));
    });
  s.erase(new_end, s.end());
  std::replace_if(s.begin(), s.end(), [&](const char& c) {
      return ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\v') || (c == '\f') || (c == '\r'));
    },' ');
  return s;
  // Below splits string by the Zs unicode  then rejoins using just whitespace.
  //   return [[newText
  //       componentsSeparatedByCharactersInSet: <- Returns an array containing substrings from the receiver that have been divided by characters in a given set.
  //           [NSCharacterSet whitespaceAndNewlineCharacterSet]] <- set is whitespace and newline
  //       componentsJoinedByString:@" "];
}
