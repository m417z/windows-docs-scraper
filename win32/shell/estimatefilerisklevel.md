# EstimateFileRiskLevel function

\[This function is available on Windows XP with Service Pack 2 (SP2) through Windows Vista. It might be altered or unavailable in subsequent versions of Windows. Client applications instead should use [**IAttachmentExecute**](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iattachmentexecute) to present a user environment that provides safe download and exchange of files through email and messaging attachments.\]

Estimates the risk of executing unknown code when a handler is called on a given file. This risk is based on an understanding of the handler and the code content of the file.

## Parameters

*pszFilePath* \[in\]

Type: **LPCWSTR**

A pointer to a null-terminated string that contains the path of the file that is being checked against the handler.

*pszExt* \[in\]

Type: **LPCWSTR**

A pointer to a null-terminated string that contains the extension of the file that is being checked, either with or without its leading period. For instance, ".txt" or "txt".

*pszHandler* \[in\]

Type: **LPCWSTR**

A pointer to a null-terminated string that contains the path of the handler for the file.

*pfrlEstimate* \[out\]

Type: **FILE\_RISK\_LEVEL\***

When this function returns successfully, contains a pointer to one of the following values that state the estimated risk.

**FRL\_NO\_OPINION** (0)

The format of the file is not identified or the handler is not identified. Insufficient information available for a meaningful answer.

**FRL\_LOW** (1)

The format of the file is completely understood, the handler is known, and there is high confidence that no extraneous code will be executed.

**FRL\_MODERATE** (2)

The format of the file is identified, but it is not sufficiently understood to label as either a high or low risk.

**FRL\_HIGH** (3)

The file format is understood and elevated risk factors have been identified.

**FRL\_BLOCK** (4)

The file format is specifically blocked for this handler.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is not declared in a public header or included in a library file. To use it you must load it directly from Winshfhc.dll by ordinal 101.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Winshfhc.dll (version 5.1 or later) |

