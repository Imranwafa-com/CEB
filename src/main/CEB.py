from bs4 import BeautifulSoup as bs4
import lxml
import os
def cmd(c):
    os.system(c)
if os.name == "nt":
    print("Running file.check.CEB.exe") # I made this part in C++ as its alot easier to there rather than in python
else:
    print("Running file.check.CEB") # I made this part in C++ as its alot easier to there rather than in python
