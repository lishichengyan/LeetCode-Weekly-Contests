  // easy
  // 主要用string的一些方法，比较直接
  int numUniqueEmails(vector<string>& emails) {
      set<string> addrs;
      for(auto email : emails){
          auto atpos = email.find("@");
          auto pluspos = email.find_first_of("+");
          string addr = email.substr(0, pluspos);
          addr.erase(remove(addr.begin(), addr.end(), '.'), addr.end()); 
          addr += email.substr(atpos, email.length());
          addrs.emplace(addr);
      }
      return addrs.size();
  }
