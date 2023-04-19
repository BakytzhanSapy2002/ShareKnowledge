import pandas as pd
import csv
class contacts:
    def __init__(self,contacts_list):
        self.list=contacts_list
    def create_contact(self,name,phone_number):
        small_list=[name,phone_number]
        self.list.append(small_list)
        print("New version of contacts")
        print(self.list)
    def edit_contact(self,choice,name,phone_number, new_name_or_phone_number):# choice integer value
# if choice=1 then i will change name, if choice=2, then i will change phone_number
        if choice==1:
            for i in range(len(self.list)):
                if self.list[i][0]==name and self.list[i][1]==phone_number:   
                    self.list[i][0]=new_name_or_phone_number # in that case, it would be new_name
            print("Edited version of contacts")
            print(self.list)
            return
        if choice==2:
            for i in range(len(self.list)):
                if self.list[i][0]==name and self.list[i][1]==phone_number:   
                    self.list[i][1]=new_name_or_phone_number # in that case, it would be new_phone_number
            print("Edited version of contacts")
            print(self.list)
            return 
        print("Unfortunately, we cannot change because of incorrect data.")
    def delete_contact(self,name,phone_number):
        index_deleted_contact=-1
        for i in range(len(self.list)):
            if self.list[i][0]==name and self.list[i][1]==phone_number:
                index_deleted_contact=i
        if index_deleted_contact==-1:
            print("Unfortunately, we cannot delete because of incorrect data.")
        else:
            self.list.pop(index_deleted_contact)
            print("New version after deleting")
            print(self.list)
    def view_contacts(self):
        print("Current version of contacts")
        print(self.list)
    def export_all_contacts(self): # I will export it to xlsx file
        pd.DataFrame(self.list).to_excel("contacts.xlsx",header=False,index_label=False)
        with open("contacts.csv","w") as f:
            wr = csv.writer(f,delimiter="\n")
            wr.writerow(self.list)
mylist=[['a','1'],['b','2'],['c','3'],['d','3']]
my_class=contacts(mylist)
my_class.export_all_contacts()
my_class.create_contact('e','5')
my_class.delete_contact('e','5')
my_class.edit_contact(2,'d','3','4')  # first argument is for the 'choice' vaiable
# if choice=1 then i will change name, if choice=2, then i will change phone_number