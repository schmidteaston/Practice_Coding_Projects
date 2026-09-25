import tkinter as tk
from locale import windows_locale


def kg_to_lbs():
   kg = float(kg_entry.get())
   lbs = kg * 2.20462
   lbs_result.config(text=f'{kg} Kilograms is equal to{lbs: .2f} Pounds!')


root = tk.Tk()
root.title("Kg to Lbs")


title = tk.Label(root, text="Kilograms to Pounds Converter!", font=("Coolvetica", 15, "bold"))
title.pack(padx=10, pady=10)
kg_entry = tk.Entry(root)
kg_entry.pack(padx=10)


enterbutton = tk.Button(root, text="Convert!", command=kg_to_lbs)
enterbutton.pack(pady=10)


lbs_result = tk.Label(root, text="", font=("Coolvertica", 12), bg="grey")
lbs_result.pack(padx=10, pady=10)


root.mainloop()
