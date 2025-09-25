# SLDepositMigrationBlob function

## Description

Deposits licensing information previously collected and gathered using the [SLGatherMigrationBlob](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slgathermigrationblob) function.

## Parameters

### `hFile` [in]

Type: **HANDLE**

The file handle for the licensing state BLOB.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **E_ACCESSDENIED**<br><br>0x80070005 | Access denied (API requires admin privileges). |