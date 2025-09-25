# DdeClientTransaction function

## Description

Begins a data transaction between a client and a server. Only a Dynamic Data Exchange (DDE) client application can call this function, and the application can use it only after establishing a conversation with the server.

## Parameters

### `pData` [in, optional]

Type: **LPBYTE**

The beginning of the data the client must pass to the server.

Optionally, an application can specify the data handle (**HDDEDATA**) to pass to the server and in that case the
*cbData* parameter should be set to -1. This parameter is required only if the
*wType* parameter is [XTYP_EXECUTE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-execute) or [XTYP_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-poke). Otherwise, this parameter should be **NULL**.

For the optional usage of this parameter, [XTYP_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-poke) transactions where
*pData* is a data handle, the handle must have been created by a previous call to the [DdeCreateDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatedatahandle) function, employing the same data format specified in the
*wFmt* parameter.

### `cbData` [in]

Type: **DWORD**

The length, in bytes, of the data pointed to by the
*pData* parameter, including the terminating **NULL**, if the data is a string. A value of -1 indicates that
*pData* is a data handle that identifies the data being sent.

### `hConv` [in]

Type: **HCONV**

A handle to the conversation in which the transaction is to take place.

### `hszItem` [in, optional]

Type: **HSZ**

A handle to the data item for which data is being exchanged during the transaction. This handle must have been created by a previous call to the [DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea) function. This parameter is ignored (and should be set to 0L) if the
*wType* parameter is
[XTYP_EXECUTE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-execute).

### `wFmt` [in]

Type: **UINT**

The standard clipboard format in which the data item is being submitted or requested.

If the transaction specified by the *wType* parameter does not pass data or is
[XTYP_EXECUTE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-execute), this parameter should be zero.

If the transaction specified by the
*wType* parameter references non-execute DDE data (
[XTYP_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-poke), [XTYP_ADVSTART](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advstart), [XTYP_ADVSTOP](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advstop),
[XTYP_REQUEST](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-request)), the
*wFmt* value must be either a valid predefined (CF_) DDE format or a valid registered clipboard format.

### `wType` [in]

Type: **UINT**

The transaction type. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **XTYP_ADVSTART**<br><br>0x1030 | Begins an advise loop. Any number of distinct advise loops can exist within a conversation. An application can alter the advise loop type by combining the [XTYP_ADVSTART](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advstart) transaction type with one or more of the following flags:<br><br>* **XTYPF_NODATA**. Instructs the server to notify the client of any data changes without actually sending the data. This flag gives the client the option of ignoring the notification or requesting the changed data from the server.<br>* **XTYPF_ACKREQ**. Instructs the server to wait until the client acknowledges that it received the previous data item before sending the next data item. This flag prevents a fast server from sending data faster than the client can process it. |
| **XTYP_ADVSTOP**<br><br>0x8040 | Ends an advise loop. |
| **XTYP_EXECUTE**<br><br>0x4050 | Begins an execute transaction. |
| **XTYP_POKE**<br><br>0x4090 | Begins a poke transaction. |
| **XTYP_REQUEST**<br><br>0x20B0 | Begins a request transaction. |

### `dwTimeout` [in]

Type: **DWORD**

The maximum amount of time, in milliseconds, that the client will wait for a response from the server application in a synchronous transaction. This parameter should be **TIMEOUT_ASYNC** for asynchronous transactions.

### `pdwResult` [out, optional]

Type: **LPDWORD**

A pointer to a variable that receives the result of the transaction. An application that does not check the result can use **NULL** for this value. For synchronous transactions, the low-order word of this variable contains any applicable DDE_ flags resulting from the transaction. This provides support for applications dependent on **DDE_APPSTATUS** bits. It is, however, recommended that applications no longer use these bits because they may not be supported in future versions of the [Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library) (DDEML). For asynchronous transactions, this variable is filled with a unique transaction identifier for use with the [DdeAbandonTransaction](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeabandontransaction) function and the [XTYP_XACT_COMPLETE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-xact-complete) transaction.

## Return value

Type: **HDDEDATA**

If the function succeeds, the return value is a data handle that identifies the data for successful synchronous transactions in which the client expects data from the server. The return value is nonzero for successful asynchronous transactions and for synchronous transactions in which the client does not expect data. The return value is zero for all unsuccessful transactions.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

When an application has finished using the data handle returned by **DdeClientTransaction**, the application should free the handle by calling the [DdeFreeDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreedatahandle) function.

Transactions can be synchronous or asynchronous. During a synchronous transaction, **DdeClientTransaction** does not return until the transaction either completes successfully or fails. Synchronous transactions cause a client to enter a modal loop while waiting for various asynchronous events. Because of this, a client application can still respond to user input while waiting on a synchronous transaction, but the application cannot begin a second synchronous transaction because of the activity associated with the first. **DdeClientTransaction** fails if any instance of the same task has a synchronous transaction already in progress.

During an asynchronous transaction, **DdeClientTransaction** returns after the transaction has begun, passing a transaction identifier for reference. When the server's DDE callback function finishes processing an asynchronous transaction, the system sends an
[XTYP_XACT_COMPLETE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-xact-complete) transaction to the client. This transaction provides the client with the results of the asynchronous transaction that it initiated by calling **DdeClientTransaction**. A client application can choose to abandon an asynchronous transaction by calling the [DdeAbandonTransaction](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeabandontransaction) function.

## See also

**Conceptual**

[DdeAbandonTransaction](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeabandontransaction)

[DdeAccessData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeaccessdata)

[DdeConnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnect)

[DdeConnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnectlist)

[DdeCreateDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatedatahandle)

[DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea)

[DdeFreeDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreedatahandle)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**

[XTYP_ADVSTART](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advstart)

[XTYP_ADVSTOP](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advstop)

[XTYP_EXECUTE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-execute)

[XTYP_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-poke)

[XTYP_REQUEST](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-request)