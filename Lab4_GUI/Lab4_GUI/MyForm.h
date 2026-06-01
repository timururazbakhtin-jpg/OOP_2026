#pragma once
#include "Lab4.h"

namespace Lab4GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		private:
			FunctionContainer* myContainer;
	public:
		MyForm(void)
		{
			InitializeComponent();
			comboBoxType->SelectedIndex = 0;
			myContainer = new FunctionContainer();
		}

	protected:
		~MyForm()
		{
			if (components) { delete components; }
			delete myContainer;
		}
	private: System::Windows::Forms::TextBox^ txtParam1;
	private: System::Windows::Forms::TextBox^ txtParam2;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::ListBox^ listBoxFunctions;
	protected:

	protected:



	private: System::Windows::Forms::ComboBox^ comboBoxType;
	private: System::Windows::Forms::TextBox^ txtParam3;
	private: System::Windows::Forms::Label^ lblParam1;
	private: System::Windows::Forms::Label^ lblParam2;

	private: System::Windows::Forms::Label^ lblParam3;
	private: System::Windows::Forms::TextBox^ txtX;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnCalculateSum;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtParam1 = (gcnew System::Windows::Forms::TextBox());
			this->txtParam2 = (gcnew System::Windows::Forms::TextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->listBoxFunctions = (gcnew System::Windows::Forms::ListBox());
			this->comboBoxType = (gcnew System::Windows::Forms::ComboBox());
			this->txtParam3 = (gcnew System::Windows::Forms::TextBox());
			this->lblParam1 = (gcnew System::Windows::Forms::Label());
			this->lblParam2 = (gcnew System::Windows::Forms::Label());
			this->lblParam3 = (gcnew System::Windows::Forms::Label());
			this->txtX = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnCalculateSum = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtParam1
			// 
			this->txtParam1->Location = System::Drawing::Point(63, 51);
			this->txtParam1->Name = L"txtParam1";
			this->txtParam1->Size = System::Drawing::Size(183, 20);
			this->txtParam1->TabIndex = 0;
			this->txtParam1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// txtParam2
			// 
			this->txtParam2->Location = System::Drawing::Point(63, 83);
			this->txtParam2->Name = L"txtParam2";
			this->txtParam2->Size = System::Drawing::Size(183, 20);
			this->txtParam2->TabIndex = 1;
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(87, 182);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(159, 38);
			this->btnAdd->TabIndex = 2;
			this->btnAdd->Text = L"Add function";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listBoxFunctions
			// 
			this->listBoxFunctions->FormattingEnabled = true;
			this->listBoxFunctions->Location = System::Drawing::Point(25, 244);
			this->listBoxFunctions->Name = L"listBoxFunctions";
			this->listBoxFunctions->Size = System::Drawing::Size(357, 160);
			this->listBoxFunctions->TabIndex = 3;
			this->listBoxFunctions->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// comboBoxType
			// 
			this->comboBoxType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxType->FormattingEnabled = true;
			this->comboBoxType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Linear", L"Quadratic", L"Harmonic" });
			this->comboBoxType->Location = System::Drawing::Point(12, 12);
			this->comboBoxType->Name = L"comboBoxType";
			this->comboBoxType->Size = System::Drawing::Size(121, 21);
			this->comboBoxType->TabIndex = 4;
			this->comboBoxType->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// txtParam3
			// 
			this->txtParam3->Location = System::Drawing::Point(63, 113);
			this->txtParam3->Name = L"txtParam3";
			this->txtParam3->Size = System::Drawing::Size(183, 20);
			this->txtParam3->TabIndex = 5;
			// 
			// lblParam1
			// 
			this->lblParam1->AutoSize = true;
			this->lblParam1->Location = System::Drawing::Point(22, 54);
			this->lblParam1->Name = L"lblParam1";
			this->lblParam1->Size = System::Drawing::Size(35, 13);
			this->lblParam1->TabIndex = 6;
			this->lblParam1->Text = L"label1";
			// 
			// lblParam2
			// 
			this->lblParam2->AutoSize = true;
			this->lblParam2->Location = System::Drawing::Point(22, 86);
			this->lblParam2->Name = L"lblParam2";
			this->lblParam2->Size = System::Drawing::Size(35, 13);
			this->lblParam2->TabIndex = 7;
			this->lblParam2->Text = L"label2";
			this->lblParam2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// lblParam3
			// 
			this->lblParam3->AutoSize = true;
			this->lblParam3->Location = System::Drawing::Point(22, 113);
			this->lblParam3->Name = L"lblParam3";
			this->lblParam3->Size = System::Drawing::Size(35, 13);
			this->lblParam3->TabIndex = 8;
			this->lblParam3->Text = L"label3";
			// 
			// txtX
			// 
			this->txtX->Location = System::Drawing::Point(361, 47);
			this->txtX->Name = L"txtX";
			this->txtX->Size = System::Drawing::Size(183, 20);
			this->txtX->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(292, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Argument x:";
			// 
			// btnCalculateSum
			// 
			this->btnCalculateSum->Location = System::Drawing::Point(424, 83);
			this->btnCalculateSum->Name = L"btnCalculateSum";
			this->btnCalculateSum->Size = System::Drawing::Size(120, 43);
			this->btnCalculateSum->TabIndex = 11;
			this->btnCalculateSum->Text = L"Calculate sum";
			this->btnCalculateSum->UseVisualStyleBackColor = true;
			this->btnCalculateSum->Click += gcnew System::EventHandler(this, &MyForm::btnCalculateSum_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 432);
			this->Controls->Add(this->btnCalculateSum);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtX);
			this->Controls->Add(this->lblParam3);
			this->Controls->Add(this->lblParam2);
			this->Controls->Add(this->lblParam1);
			this->Controls->Add(this->txtParam3);
			this->Controls->Add(this->comboBoxType);
			this->Controls->Add(this->listBoxFunctions);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->txtParam2);
			this->Controls->Add(this->txtParam1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comboBoxType->SelectedIndex == -1) {
			MessageBox::Show("Please choose function type!", "Error");
			return;
		}

		try {
			double p1 = System::Convert::ToDouble(txtParam1->Text);
			double p2 = System::Convert::ToDouble(txtParam2->Text);

			ParametricFunction* newFunc = nullptr;

			if (comboBoxType->SelectedIndex == 0) {
				newFunc = new LinearFunction(p1, p2);
			}
			else {
				double p3 = System::Convert::ToDouble(txtParam3->Text);

				if (comboBoxType->SelectedIndex == 1) { 
					newFunc = new QuadraticFunction(p1, p2, p3);
				}
				else if (comboBoxType->SelectedIndex == 2) { 
					newFunc = new HarmonicFunction(p1, p2, p3);
				}
			}

			if (newFunc != nullptr) {
				myContainer->addFunction(newFunc);

				listBoxFunctions->Items->Clear();
				std::vector<std::string> info = myContainer->getAllFunctionsInfo();

				for (const auto& str : info) {
					listBoxFunctions->Items->Add(gcnew System::String(str.c_str()));
				}
			}
		}
		catch (System::FormatException^) {
			MessageBox::Show("Please use only correct numeric values!", "Input error");
		}
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = comboBoxType->SelectedIndex;

	if (selectedIndex == 0) {
		lblParam1->Text = "a:";
		lblParam2->Text = "b:";
		lblParam3->Visible = false;
		txtParam3->Visible = false;
	}
	else if (selectedIndex == 1) {
		lblParam1->Text = "a:";
		lblParam2->Text = "b:";
		lblParam3->Text = "c:";
		lblParam3->Visible = true;
		txtParam3->Visible = true;
	}
	else if (selectedIndex == 2) {
		lblParam1->Text = "A:";
		lblParam2->Text = "omega:";
		lblParam3->Text = "phi:";
		lblParam3->Visible = true;
		txtParam3->Visible = true;
	}
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnCalculateSum_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		double x = System::Convert::ToDouble(txtX->Text);
		double result = myContainer->calculateSum(x);
		MessageBox::Show("Sum of function values: " + result.ToString(), "Result");
	}
	catch (System::FormatException^) {
		MessageBox::Show("Please input correct value of x!", "Error");
	}
}
};
}
