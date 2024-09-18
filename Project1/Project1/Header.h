#pragma once

namespace Project1 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            // Добавляем обработчик события MouseClick
            this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->SuspendLayout();
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 450);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->ResumeLayout(false);
        }

        // Обработчик события MouseClick
        void MyForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
        {
            Random^ rand = gcnew Random();
            this->BackColor = Color::FromArgb(rand->Next(256), rand->Next(256), rand->Next(256));
        }
    };
}
