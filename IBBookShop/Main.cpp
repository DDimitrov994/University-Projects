//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IBAuthorsTblBeforePost(TDataSet *DataSet)
{
           if(IBAuthorsTbl->State == dsInsert)
      {
      IBAuthorsSP->Prepare();
      IBAuthorsSP->ExecProc();
      IBAuthorsTbl->FieldByName("ID")->AsInteger =
         IBAuthorsSP->ParamByName("ID")->AsInteger;
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AuthorsDBGExit(TObject *Sender)
{
if((IBAuthorsTbl->State == dsInsert) ||
      (IBAuthorsTbl->State == dsEdit))
         IBAuthorsTbl->Post();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IBBooksTblBeforePost(TDataSet *DataSet)
{
   if(IBBooksTbl->State == dsInsert)
      {
      IBBooksSP->Prepare();
      IBBooksSP->ExecProc();
      IBBooksTbl->FieldByName("ID")->AsInteger =
         IBBooksSP->ParamByName("ID")->AsInteger;
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BooksDBGExit(TObject *Sender)
{
if((IBBooksTbl->State == dsInsert) ||
      (IBBooksTbl->State == dsEdit))
         IBBooksTbl->Post();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroupClick(TObject *Sender)
{
switch(RadioGroup->ItemIndex)
      {
      case 0 : IBAuthorsTbl->IndexName = "AuthorsTblNameNDX"; break;
      case 1 : IBAuthorsTbl->IndexName = "AuthorsTblFamNDX"; break;
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SearchEBChange(TObject *Sender)
{
  TLocateOptions Opts; Opts.Clear(); Opts << loPartialKey;
   
   switch(RadioGroup->ItemIndex)
      {
      case 0 : IBAuthorsTbl->Locate("NAME", SearchEB->Text, Opts); break;
      case 1 : IBAuthorsTbl->Locate("FAM", SearchEB->Text, Opts); break;
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SQLBitBtnClick(TObject *Sender)
{
        IBQuery->Close();
        IBQuery->Prepare();
        IBQuery->ParamByName("PNAME")->AsString = SQLEB->Text;
        IBQuery->Open();
}
//---------------------------------------------------------------------------

