import datetime
import time
        
class PostcardList:
    
    #file name, eventually with the full path
    _file = ""
    
    #list of postcards read from _file
    _postcards = list()
    
    #is a dict where the key is the string date, and the value is a list of indices. 
    #Each index refers to the corresponding record
    _date = dict()
    
    #is a dict where the key is the string sender, and the value is a list of indices. 
    #Each index refers to the corresponding record.
    _from = dict() 
    
    #is a dict where the key is the string receiver, and the value is a list of indices. 
    #Each index refers to the corresponding record.
    _to = dict()
    

    # Class PostcardList must manage the I/O file through the following member functions.
    # Note that you are free to choose the appropriate arguments, but the function names must be as follows:
    
    def writeFile(self, file):
        
        '''write self.{_date,_from,_to} to self._file'''
        
        try:
            
            with open(file,'w') as f:
                for p in self._postcards :
                    f.write(p+"\n")
                    
        except Exception as e:
            
            print(e)
        
    def readFile(self,file):
        
        '''from self._file read self.{_date,_from,_to}'''
        
        self._postcards = []
        self.updateLists(file)
        
    def parsePostcards(self):
        
        ''' parse self._postcards, set self.{_date,_from,_to} '''
        
        for i,postcard in enumerate(self._postcards):

            postcard = postcard.replace(" ","").split(";")
            Date = postcard[0].split(":")[1]
            Date = datetime.datetime.strptime(Date,"%Y-%m-%d").date()
            self._date.setdefault(Date,[]).append(i)

            From = postcard[1].split(":")[1]
            self._from.setdefault(From,[]).append(i)

            To = postcard[2].split(":")[1]
            self._to.setdefault(To,[]).append(i)

    def updateFile(self,file): 
        
        '''as write but appending to self._file ''' 
        
        try:
            
            with open(file,'a') as f:
                for postcard in self._postcards :
                    f.write(p)
                    
        except Exception as e:
            print(e)
    
    
    def updateLists(self, file): 
        
        '''as read but appending to self._postcards'''
        
        self._date = {}
        self._from = {}
        self._to = {}
        
        try:
            
            with open(file,'r') as f:
                
                for line in f:
                    self._postcards.append(str(line))
                    
            self.parsePostcards()
            
        except Exception as e:
            print(e)
                
    def getNumberOfPostcards(self): 
        
        '''returns length of self._postcards'''
        
        return len(self._postcards)
        
        
    # Class PostcardList must manage the sorting of dates/senders/receivers. 
    # Note that the names and arguments of the functions are fixed as follows:
    
    def getPostcardsByDateRange(self,date_range):
        
        '''returns the postcards within a date_range'''
        
        try:
            
            postcard_in_range = list()
            m = date_range[0].date()
            M = date_range[1].date()
            
            for i in self._date:
                if (i >= m and i <= M):
                    for j in self._date[i]:
                        postcard_in_range.append(self._postcards[j])
                        
            return postcard_in_range
        
        except Exception as e:
            
            print(e)

    def getPostcardsBySender(self, sender):
        
        '''returns the postcards from a sender'''
        
        postcard_by_sender = list()
        
        if sender not in self._from:
            pass
        else:
            for i in self._from[sender]:
                postcard_by_sender.append(self._postcards[i])
                
        return postcard_by_sender

    def getPostcardsByReceiver(self, receiver): 
        
        '''returns the postcards to a receiver'''
        
        postcard_by_receiver = list()
        
        if receiver not in self._to:
            pass
        else:
            for i in self._to[receiver]:
                postcard_by_receiver.append(self._postcards[i])
                
        return postcard_by_receiver