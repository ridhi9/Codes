 //Function to find the maximum number of meetings that can
    //be performed in a meeting room
    //for sorting the start time and end time according to any one of them but generally we sort according to the end time as the start 
    //time of second(current) meeting should be greater than end time of previous meeting
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            //
            pair<int,int> p =make_pair(start[i],end[i]);
            v.push_back(p);
        }
        //for sorting the start time and end time according to any one of them but generally we sort according to the end time as the start 
    //time of second(current) meeting should be greater than end time of previous meeting
        sort(v.begin(),v.end(),cmp);
        //start initially with count 1 for curr meeting
        int count=1;
        //initialise ansEnd with end timing of first meeting
        int ansEnd=v[0].second;
        for(int i=1;i<n;i++){
            //if start time of curr meeting is greater than ansEnd of laast meeting then go ahead and increase count ns update asEnd
            if(v[i].first>ansEnd){
                count++;
                ansEnd=v[i].second;
            }
        }
        return count;
    } 
