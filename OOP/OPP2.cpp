#include <iostream>
#include <vector>
#include <string>

class PhoneBookEntry {
private:
    char* fullName;
    std::string homePhone;
    std::string workPhone;
    std::string mobilePhone;
    std::string additionalInfo;

public:
   
    PhoneBookEntry(const char* name, const std::string& home, const std::string& work,
        const std::string& mobile, const std::string& info) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
        homePhone = home;
        workPhone = work;
        mobilePhone = mobile;
        additionalInfo = info;
    }

    ~PhoneBookEntry() {
        delete[] fullName;
    }

    const char* getName() const { return fullName; }
    std::string getHomePhone() const { return homePhone; }
    std::string getWorkPhone() const { return workPhone; }
    std::string getMobilePhone() const { return mobilePhone; }
    std::string getAdditionalInfo() const { return additionalInfo; }

    void setName(const char* name) {
        delete[] fullName;
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    }
    void setHomePhone(const std::string& home) { homePhone = home; }
    void setWorkPhone(const std::string& work) { workPhone = work; }
    void setMobilePhone(const std::string& mobile) { mobilePhone = mobile; }
    void setAdditionalInfo(const std::string& info) { additionalInfo = info; }
};

class PhoneBook {
private:
    std::vector<PhoneBookEntry> entries;

public:
    void addEntry(const PhoneBookEntry& entry) {
        entries.push_back(entry);
    }

    void removeEntry(const char* name) {
        entries.erase(
            std::remove_if(entries.begin(), entries.end(),
                [name](const PhoneBookEntry& entry) { return strcmp(entry.getName(), name) == 0; }),
            entries.end());
    }

    PhoneBookEntry* findEntry(const char* name) {
        for (auto& entry : entries) {
            if (strcmp(entry.getName(), name) == 0) {
                return &entry;
            }
        }
        return nullptr;
    }

    void printAllEntries() {
        for (const auto& entry : entries) {
            std::cout << "Name: " << entry.getName() << std::endl
                << "Home Phone: " << entry.getHomePhone() << std::endl
                << "Work Phone: " << entry.getWorkPhone() << std::endl
                << "Mobile Phone: " << entry.getMobilePhone() << std::endl
                << "Additional Info: " << entry.getAdditionalInfo() << std::endl << std::endl;
        }
    }



};

int main() {

    PhoneBook myPhoneBook;
    myPhoneBook.addEntry(PhoneBookEntry("John Doe", "123-4567", "765-4321", "987-6543", "Friend from work"));
    myPhoneBook.addEntry(PhoneBookEntry("Jane Smith", "555-1234", "555-5678", "555-6789", "Neighbour"));

    myPhoneBook.printAllEntries();

    return 0;
