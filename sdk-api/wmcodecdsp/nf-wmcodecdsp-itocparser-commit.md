# ITocParser::Commit

## Description

The **Commit** method stores the current state of the TOC Parser object in its associated media file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You can associate a TOC Parser object with a media file by calling [ITocParser::Init](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocparser-init). As you add, modify, or remove tables of contents from the TOC Parser object, those changes are made only to the TOC Parser object in memory, not to the media file. To store your changes in the media file, you must call **ITocParser::Commit**.

## See also

[ITocParser](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocparser)