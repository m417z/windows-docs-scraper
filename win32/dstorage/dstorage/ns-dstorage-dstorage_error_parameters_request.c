struct DSTORAGE_ERROR_PARAMETERS_REQUEST {
  WCHAR            Filename[MAX_PATH];
  CHAR             RequestName[MAX_PATH];
  DSTORAGE_REQUEST Request;
};