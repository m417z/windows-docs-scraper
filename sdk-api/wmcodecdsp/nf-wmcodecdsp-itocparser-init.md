# ITocParser::Init

## Description

The **Init** method initializes the TOC Parser object and associates it with a media file.

## Parameters

### `pwszFileName` [in]

Pointer to a NULL-terminated wide-character string that specifies the path of the media file. See Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The path that you pass in *pwszFileName* must be a long Universal Naming Convention (UNC) file path. A long UNC file path begins with "\\?\". The following line of code shows how to set the path for the file c:\experiment\seattle.wmv.

`pTocParser->Init(L"\\\\?\\c:\\experiment\\seattle.wmv");`

## See also

[ITocParser](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocparser)