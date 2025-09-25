# IOfflineFilesCache::Encrypt

## Description

Encrypts or unencrypts the contents of the Offline Files cache cached for the calling user. When the cache is encrypted, all files subsequently cached are automatically encrypted. When the cache is unencrypted, all files subsequently cached are cached unencrypted.

Existing files in the cache are either encrypted or unencrypted to match the new state of the cache.

## Parameters

### `hwndParent` [in]

Identifies the parent window for any user interface elements displayed. This parameter is ignored if the **OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_INTERACTIVE** flag is not set in the *dwEncryptionControlFlags* parameter.

### `bEncrypt` [in]

**TRUE** to encrypt, **FALSE** to unencrypt.

### `dwEncryptionControlFlags` [in]

This parameter can be one or more of the following values.

#### OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_LOWPRIORITY (0x00000200)

Reserved for future use.

#### OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_ASYNCPROGRESS (0x00000400)

Progress is reported to the progress interface asynchronously with the actual operations. For more information about behavior, see the Asynchronous Progress Notifications section. If this flag is not set, progress is reported synchronously with each operation.

#### OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_INTERACTIVE (0x00000800)

Set this flag if the operation is allowed to display user interface elements as necessary. An example is the system's credential-request dialog. If this flag is set, the value in *hwndParent* is used as the parent for any user interface elements displayed.

#### OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_CONSOLE (0x00001000)

This flag is ignored if the **OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_INTERACTIVE** flag is not set. If the **OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_INTERACTIVE** flag is set, this flag indicates that any UI produced should be directed to the console window associated with the process invoking the operation.

#### OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_BACKGROUND (0x00010000)

Set this flag if you want the encryption operation to avoid sharing violations in the event that an application wishes to open a file that is currently open for the encryption operation. When that scenario occurs and this flag is set, the encryption operation immediately stops processing that particular file at that time. This flag is primarily used by the Offline Files service when ensuring cache encryption at user logon. Normally a client calling this method would not set this flag.

### `bAsync` [in]

Indicates whether the operation is to be performed asynchronously. If this parameter is **TRUE**, the operation is scheduled for asynchronous operation and the function returns immediately. If this parameter is **FALSE**, the function returns when the operation is complete.

### `pIProgress` [in]

Interface to an event sink that will receive progress events during the operation. If events are not desired, this parameter may be **NULL**. Note that this parameter is highly recommended for asynchronous operation. A progress implementation is the only way to be notified when the asynchronous operation completes.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

Returns `HRESULT_FROM_WIN32(ERROR_CANCELLED)` if the operation is canceled.

## Remarks

Cancellation of this operation does not restore the cached files to their prior encryption state. This may leave the cache in a partially encrypted or unencrypted state. The same condition can occur if the operation is aborted due to an error. To resolve the partial state, repeat the operation until successful completion.

Also note that the Offline Files service automatically performs the encryption operation in the background following user logon. This ensures that all files cached by that user are in the correct state - encrypted or unencrypted – to match the state of the cache.

| If canceled while... | Cache state is... | New cached files will be... |
| --- | --- | --- |
| Encrypting | Partially encrypted | Encrypted |
| Unencrypting | Partially unencrypted | Unencrypted |

The current encryption state of the Offline Files cache can be checked by using the Offline Files Control Panel or by calling [IOfflineFilesCache::GetEncryptionStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-getencryptionstatus).

The caller can implement the progress callback methods in the following list to obtain the progress information for each processed file and directory.

| Progress Events Interface | Method | Description |
| --- | --- | --- |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [Begin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-begin) | Called at the start of the operation. |
| [IOfflineFilesSimpleProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessimpleprogress) | [ItemBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessimpleprogress-itembegin) | Called at the start of processing for each file. |
| [IOfflineFilesSimpleProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessimpleprogress) | [ItemResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessimpleprogress-itemresult) | Called after each file is encrypted. |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [QueryAbort](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-queryabort) | Called periodically during the sync operation to detect a request for cancellation. |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [End](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-end) | Called at the end of the operation. |

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)