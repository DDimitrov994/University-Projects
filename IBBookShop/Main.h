//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBStoredProc.hpp>
#include <IBTable.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <IBQuery.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TIBDatabase *IBDB;
        TIBTransaction *IBTS;
        TIBTable *IBAuthorsTbl;
        TDataSource *IBAuthorsDS;
        TDBGrid *AuthorsDBG;
        TIBStoredProc *IBAuthorsSP;
        TIBTable *IBBooksTbl;
        TDataSource *IBBooksDS;
        TDBGrid *BooksDBG;
        TIBStoredProc *IBBooksSP;
        TIntegerField *IBBooksTblID;
        TIntegerField *IBBooksTblAID;
        TIntegerField *IBBooksTblGID;
        TIBStringField *IBBooksTblISBN;
        TIBStringField *IBBooksTblNAME;
        TIBTable *IBGenresTbl;
        TStringField *IBBooksTblGenre;
        TRadioGroup *RadioGroup;
        TEdit *SearchEB;
        TEdit *SQLEB;
        TBitBtn *SQLBitBtn;
        TIBQuery *IBQuery;
        TDBGrid *DBGrid1;
        TDataSource *IBQuerryDS;
        void __fastcall IBAuthorsTblBeforePost(TDataSet *DataSet);
        void __fastcall AuthorsDBGExit(TObject *Sender);
        void __fastcall IBBooksTblBeforePost(TDataSet *DataSet);
        void __fastcall BooksDBGExit(TObject *Sender);
        void __fastcall RadioGroupClick(TObject *Sender);
        void __fastcall SearchEBChange(TObject *Sender);
        void __fastcall SQLBitBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
