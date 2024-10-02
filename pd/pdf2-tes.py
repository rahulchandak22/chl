import PyPDF2

def read_protected_pdf(file_path, password):
    # Open the PDF file
    with open(file_path, 'rb') as file:
        # Create a PDF reader object
        reader = PyPDF2.PdfReader(file)
        
        # Try to decrypt the PDF with the provided password
        if reader.decrypt(password):
            # If decryption is successful, read the content
            for page in range(len(reader.pages)):
                print(reader.pages[page].extract_text())
        else:
            print("Incorrect password or failed to decrypt the PDF.")

# Example usage
file_path = 'path/to/your/protected.pdf'
password = 'your_password'
read_protected_pdf(file_path, password)
