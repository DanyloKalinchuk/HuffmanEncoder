import tkinter as tk
from tkinter import filedialog

def encode(event=None):
    text = txt_box.get('0.0', 'end')
    if text.strip() and output_path:
        lbl_state.configure(text="Outpud Saved!")
    else:
        if not text.strip() and not output_path:
            lbl_state.configure(text="No input and output path given")
        elif not output_path:
            lbl_state.configure(text="No output path chosen")
        else:
            lbl_state.configure(text="No input given")

def browse_files(event=None):
    filename = filedialog.askopenfilename(initialdir="/", title="Select a File", filetypes=(("Text files", "*.txt*"),))
    if filename:
        with open(filename, encoding='utf-8') as file:
            content = file.read()
            txt_box.delete('1.0', 'end')
            txt_box.insert('1.0', content)

def get_path(event=None):
    global output_path
    output_path = filedialog.askdirectory(initialdir="/", title="Select a path")
    if output_path:
        lbl_output.config(text=f"Output directory is: {output_path}")
    else:
        lbl_output.config(text="Choose output directory")

output_path = ""

root = tk.Tk()
root.title("Huffman Encoder")
root.geometry("600x375")

root.columnconfigure(0, weight=3)
root.columnconfigure(1, weight=1)
root.rowconfigure(0, weight=1)

frame_input = tk.Frame(root)
frame_input.grid(row=0, column=0, sticky="nsew", padx=3, pady=3)

frame_input.columnconfigure(0, weight=1)

txt_box = tk.Text(frame_input, font=('System 15'), height=12, width=12)
txt_box.grid(row=0, column=0, sticky="ew", padx=5, pady=5)

frame_btns = tk.Frame(root)
frame_btns.grid(row=0, column=1, sticky="nsew")

frame_btns.columnconfigure(0, weight=1)

btn_from_txt = tk.Button(frame_btns, text="Import from .txt file", command=browse_files, height=7)
btn_from_txt.grid(row=0, column=0, sticky="new", padx=5, pady=6)

btn_encode = tk.Button(frame_btns, text="Encode", command=encode, height=7)
btn_encode.grid(row=1, column=0, sticky="new", padx=5, pady=6)

frame_output = tk.Frame(frame_input)
frame_output.grid(row=1, column=0, sticky="nsew", padx=3, pady=3)

frame_output.rowconfigure((0,1), weight=1)
frame_output.columnconfigure(0, weight=1)

lbl_output = tk.Label(frame_output, text="Choose output directory")
lbl_output.grid(row=0, column=0, sticky="new")

btn_output = tk.Button(frame_output, text="Select output directory", command=get_path, height=5)
btn_output.grid(row=1, column=0, sticky="new")

lbl_state = tk.Label(frame_output, text="")
lbl_state.grid(row=2, column=0, sticky="new")

root.mainloop()