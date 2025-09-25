# OleSavePictureFile function

## Description

Saves a picture to a file.

## Parameters

### `lpdispPicture` [in]

Points to the **IPictureDisp** picture object.

### `bstrFileName` [in]

The name of the file to save the picture to.

## Return value

This method returns standard COM error codes in addition to the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CTL_E_INVALIDPROPERTYVALUE** | *lpdispPicture* is **NULL**. |
| **CTL_E_FILENOTFOUND** | *bstrFileName* cannot be found. |