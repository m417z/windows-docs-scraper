# SLGatherMigrationBlob function

## Description

Gathers licensing information for the provided file handle. This licensing information
can later be applied or deposited using the [SLDepositMigrationBlob](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-sldepositmigrationblob) function.

## Parameters

### `bMigratableOnly` [in]

Type: **BOOL**

**TRUE** if only data that can be migrated should be gathered; **FALSE** otherwise.

### `pwszEncryptorUri` [in, optional]

Type: **LPCWSTR**

The URI of the encrypting session key used to encrypt
any sensitive data in the output BLOB. Only valid values are **NULL** and **SL_DEFAULT_MIGRATION_ENCRYPTOR_URI**,
which both refer to the same key.

### `hFile` [in]

Type: **HANDLE**

The handle to the file where the licensing state BLOB should be written.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **E_ACCESSDENIED**<br><br>0x80070005 | Access denied (API requires admin privileges). |