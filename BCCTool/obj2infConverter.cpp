#include "obj2infConverter.h"
#include "Model.h"

System::Void BCCTool::obj2infConverter::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool success = false;

	if (checkBox1->Checked)
	{
		obj.Reset(true, 0);

		success = true;
	}
	else
	{
		if (textBox1->Text != "")
		{
			int texture = Convert::ToInt32(textBox1->Text);

			if (texture >= 0 && texture <= 3000)
			{
				obj.Reset(false, texture);

				success = true;
			}
			else
				MessageBox::Show
				(
					"The texture number is set incorrectly. Enter a number from 0 to 3000.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
		}
		else
			MessageBox::Show
			(
				"The texture number is set incorrectly. Enter a number from 0 to 3000.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
	}

	if (success)
	{
		obj.Convert();

		Model::SetCounts(obj.verNum, obj.facesNum);
		Model::SetVertices(obj.tempVertices);
		Model::SetTriangles(obj._verTriangles);

		this->Close();
	}
}