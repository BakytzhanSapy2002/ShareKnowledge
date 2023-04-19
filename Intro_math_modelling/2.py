import csv
class all_contacts:
    def __init__(self,contacts_dictionary):
        self.contacts=contacts_dictionary
    def create_contact(self,name,phone_number):
        self.contacts[name]=phone_number
        print("Version after adding contact")
        print(self.contacts)
    def edit_contact(self,choice,name,phone_number, name_or_phone_number):
        x=self.contacts.keys()
        if choice==1:
            for i in x:
                if i==name:
                    if self.contacts[name]==phone_number:   
                        value=self.contacts[name]
                        self.contacts.pop(name)
                        self.contacts[name_or_phone_number]=value
                        break
            print("Version after updating")
            print(self.contacts)
        else:
            if choice==2:
                for i in x:
                    if i==name:
                        if self.contacts[name]==phone_number:   
                            self.contacts[i]=name_or_phone_number 
                            break
                print("Version after updating")
                print(self.contacts) 
            else:    
                print("Name or phone number is not correct")
    def delete_contact(self,name,phone_number):
        x=self.contacts.keys()
        for i in x:
            if i==name:
                if self.contacts[name]==phone_number:
                    self.contacts.pop(name)
                    print("New version after deleting")
                    print(self.contacts)
                    return
        print("Name or phone number is not correct")
    def view_contacts(self):
        print("Current version of all_contacts")
        print(self.contacts)
    def export_all_contacts(self): # I will export it to txt file
        with open ("Contacts.txt",'w') as txtfile:
            for name,phone in self.contacts.items():
                txtfile.write(str(name) +  " ==> "+str(phone)+'\n')
my_dictionary={"Abay":"1845","Mukhtar":"1961","Men":"2022"}
my_class=all_contacts(my_dictionary)
# my_class.export_all_contacts()
my_class.create_contact('Ereke','1985')
my_class.delete_contact('Messi','1987')
my_class.delete_contact('Men','2022')
my_class.edit_contact(1,'Ereke','1985','Ronaldo')  # first argument is for the 'choice' vaiable
# if choice=1 then i will change name, if choice=2, then i will change phone_number
my_class.export_all_contacts()