object Form1: TForm1
  Left = 201
  Top = 138
  Width = 928
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object AuthorsDBG: TDBGrid
    Left = 8
    Top = 80
    Width = 320
    Height = 120
    DataSource = IBAuthorsDS
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnExit = AuthorsDBGExit
  end
  object BooksDBG: TDBGrid
    Left = 8
    Top = 256
    Width = 433
    Height = 120
    DataSource = IBBooksDS
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnExit = BooksDBGExit
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'AID'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'GID'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ISBN'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAME'
        Width = 158
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Genre'
        Visible = True
      end>
  end
  object RadioGroup: TRadioGroup
    Left = 328
    Top = 80
    Width = 185
    Height = 105
    Caption = 'RadioGroup'
    ItemIndex = 0
    Items.Strings = (
      'NAME'
      'FAM')
    TabOrder = 2
    OnClick = RadioGroupClick
  end
  object SearchEB: TEdit
    Left = 176
    Top = 48
    Width = 209
    Height = 21
    TabOrder = 3
    OnChange = SearchEBChange
  end
  object SQLEB: TEdit
    Left = 560
    Top = 56
    Width = 193
    Height = 21
    TabOrder = 4
  end
  object SQLBitBtn: TBitBtn
    Left = 768
    Top = 56
    Width = 105
    Height = 25
    Caption = 'SQL'
    TabOrder = 5
    OnClick = SQLBitBtnClick
  end
  object DBGrid1: TDBGrid
    Left = 520
    Top = 152
    Width = 385
    Height = 120
    DataSource = IBQuerryDS
    TabOrder = 6
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object IBDB: TIBDatabase
    Connected = True
    DatabaseName = 'C:\Users\shayf\Desktop\IBBookShop\Data\IBBOOKSHOP.GDB'
    Params.Strings = (
      'user_name=SYSDBA'
      'password=masterkey')
    LoginPrompt = False
    DefaultTransaction = IBTS
    IdleTimer = 0
    SQLDialect = 3
    TraceFlags = []
    Left = 48
    Top = 16
  end
  object IBTS: TIBTransaction
    Active = True
    DefaultDatabase = IBDB
    AutoStopAction = saNone
    Left = 88
    Top = 16
  end
  object IBAuthorsTbl: TIBTable
    Database = IBDB
    Transaction = IBTS
    BeforePost = IBAuthorsTblBeforePost
    Active = True
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'ID'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'NAME'
        DataType = ftString
        Size = 12
      end
      item
        Name = 'FAM'
        DataType = ftString
        Size = 15
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY1'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'AUTHORSTBLNAMENDX'
        Fields = 'NAME'
      end
      item
        Name = 'AUTHORSTBLFAMNDX'
        Fields = 'FAM'
      end>
    StoreDefs = True
    TableName = 'AUTHORS_TBL'
    Left = 48
    Top = 48
  end
  object IBAuthorsDS: TDataSource
    DataSet = IBAuthorsTbl
    Left = 88
    Top = 48
  end
  object IBAuthorsSP: TIBStoredProc
    Database = IBDB
    Transaction = IBTS
    StoredProcName = 'AUTHORSTBL_IDSP'
    Left = 128
    Top = 48
  end
  object IBBooksTbl: TIBTable
    Database = IBDB
    Transaction = IBTS
    BeforePost = IBBooksTblBeforePost
    Active = True
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'ID'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'AID'
        DataType = ftInteger
      end
      item
        Name = 'GID'
        DataType = ftInteger
      end
      item
        Name = 'ISBN'
        DataType = ftString
        Size = 12
      end
      item
        Name = 'NAME'
        DataType = ftString
        Size = 50
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY3'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'RDB$FOREIGN4'
        Fields = 'AID'
      end
      item
        Name = 'RDB$FOREIGN5'
        Fields = 'GID'
      end>
    IndexFieldNames = 'AID'
    MasterFields = 'ID'
    MasterSource = IBAuthorsDS
    StoreDefs = True
    TableName = 'BOOKS_TBL'
    Left = 48
    Top = 216
    object IBBooksTblID: TIntegerField
      FieldName = 'ID'
    end
    object IBBooksTblAID: TIntegerField
      FieldName = 'AID'
    end
    object IBBooksTblGID: TIntegerField
      FieldName = 'GID'
    end
    object IBBooksTblISBN: TIBStringField
      FieldName = 'ISBN'
      Size = 12
    end
    object IBBooksTblNAME: TIBStringField
      FieldName = 'NAME'
      Size = 50
    end
    object IBBooksTblGenre: TStringField
      FieldKind = fkLookup
      FieldName = 'Genre'
      LookupDataSet = IBGenresTbl
      LookupKeyFields = 'ID'
      LookupResultField = 'NAME'
      KeyFields = 'GID'
      Lookup = True
    end
  end
  object IBBooksDS: TDataSource
    DataSet = IBBooksTbl
    Left = 96
    Top = 216
  end
  object IBBooksSP: TIBStoredProc
    Database = IBDB
    Transaction = IBTS
    StoredProcName = 'BOOKSTBL_IDSP'
    Left = 136
    Top = 216
  end
  object IBGenresTbl: TIBTable
    Database = IBDB
    Transaction = IBTS
    Active = True
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'ID'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'NAME'
        DataType = ftString
        Size = 15
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY2'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end>
    StoreDefs = True
    TableName = 'GENRES_TBL'
    Left = 184
    Top = 216
  end
  object IBQuery: TIBQuery
    Database = IBDB
    Transaction = IBTS
    BufferChunks = 1000
    CachedUpdates = False
    DataSource = IBBooksDS
    SQL.Strings = (
      'SELECT A.NAME as AUTHOR, B.NAME as BOOK, G.NAME AS GENRE'
      'FROM GENRES_TBL G, BOOKS_TBL B, AUTHORS_TBL A'
      'WHERE G.NAME LIKE :PNAME AND G.ID = B.GID AND B.AID = A.ID')
    Left = 568
    Top = 96
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PNAME'
        ParamType = ptUnknown
      end>
  end
  object IBQuerryDS: TDataSource
    DataSet = IBQuery
    Left = 608
    Top = 104
  end
end
