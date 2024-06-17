class tNode:
    def __init__(self, data=""):
        self.data = data
        self.next = None

class tList:
    def __init__(self):
        self.first_elem = None

def insert_list(list_obj, new_data):
    new_node = tNode(new_data)
    new_node.next = list_obj.first_elem
    list_obj.first_elem = new_node

def remove_list(list_obj, del_data):
    if not list_obj.first_elem:
        print("Cannot delete from an empty list.")
        return

    current = list_obj.first_elem
    prev = None

    while current and current.data != del_data:
        prev = current
        current = current.next

    if current:
        if prev is None:
            list_obj.first_elem = current.next
        else:
            prev.next = current.next
    else:
        print(f"Node with data {del_data} not found in the list.")

def free_list(list_obj):
    current = list_obj.first_elem
    while current:
        temp = current
        current = current.next
        del temp

def print_list(list_obj):
    current = list_obj.first_elem
    print("List elements:", end=" ")
    while current:
        print(current.data, end=" ")
        current = current.next
    print()

def create_list():
    return tList()
