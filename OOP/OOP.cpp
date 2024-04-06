#include <vector>
#include <algorithm> 
#include <string>

struct StudentGrade {
    std::string name;
    char mark;
};

class GradeMap {
private:
    std::vector<StudentGrade> m_map;

public:
    GradeMap() {}

   
    char& operator[](const std::string& name) {
       
        auto it = std::find_if(m_map.begin(), m_map.end(), [&name](const StudentGrade& sg) {
            return sg.name == name;
            });

       
        if (it != m_map.end()) {
            return it->mark;
        }
  
        m_map.push_back({ name, ' ' }); 
        return m_map.back().mark; 
    }
};