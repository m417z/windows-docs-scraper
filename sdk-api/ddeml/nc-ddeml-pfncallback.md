## Description

An application-defined callback function used with the [Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library) (DDEML) functions. It processes Dynamic Data Exchange (DDE) transactions. The
**PFNCALLBACK** type defines a pointer to this callback function. *DdeCallback* is a placeholder for the application-defined function name.

## Parameters

### `wType` [in]

Type: **UINT**

The type of the current transaction. This parameter consists of a combination of transaction class flags and transaction type flags. The following table describes each of the transaction classes and provides a list of the transaction types in each class. For information about a specific transaction type, see the individual description of that type in **Remarks**.

### `wFmt` [in]

Type: **UINT**

The format in which data is sent or received.

### `hConv` [in]

Type: **HCONV**

A handle to the conversation associated with the current transaction.

### `hsz1` [in]

Type: **HSZ**

A handle to a string. The meaning of this parameter depends on the type of the current transaction. For the meaning of this parameter, see the description of the transaction type in **Remarks**.

### `hsz2` [in]

Type: **HSZ**

A handle to a string. The meaning of this parameter depends on the type of the current transaction. For the meaning of this parameter, see the description of the transaction type in **Remarks**.

### `hData` [in]

Type: **HDDEDATA**

A handle to DDE data. The meaning of this parameter depends on the type of the current transaction. For the meaning of this parameter, see the description of the transaction type in **Remarks**.

### `dwData1` [in]

Type: **ULONG_PTR**

Transaction-specific data. For the meaning of this parameter, see the description of the transaction type in **Remarks**.

### `dwData2` [in]

Type: **ULONG_PTR**

Transaction-specific data. For the meaning of this parameter, see the description of the transaction type in **Remarks**.

## Return value

Type: **HDDEDATA**

The return value depends on the transaction class. For more information about the return values, see descriptions of the individual transaction types.

## Remarks

### XCLASS_BOOL

A DDE callback function should return **TRUE** or **FALSE** when it finishes processing a transaction that belongs to this class. The **XCLASS_BOOL** transaction class consists of the following types:

* [XTYP_ADVSTART](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advstart)
* [XTYP_CONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-connect)

### XCLASS_DATA

A DDE callback function should return a DDE handle, the **CBR_BLOCK** return code, or **NULL** when it finishes processing a transaction that belongs to this class. The **XCLASS_DATA** transaction class consists of the following types:

* [XTYP_ADVREQ](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advreq)
* [XTYP_REQUEST](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-request)
* [XTYP_WILDCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-wildconnect)

### XCLASS_FLAGS

A DDE callback function should return **DDE_FACK**, **DDE_FBUSY**, or **DDE_FNOTPROCESSED** when it finishes processing a transaction that belongs to this class. The **XCLASS_FLAGS** transaction class consists of the following types:

* [XTYP_ADVDATA](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advdata)
* [XTYP_EXECUTE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-execute)
* [XTYP_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-poke)

### XCLASS_NOTIFICATION

The transaction types that belong to this class are for notification purposes only. The return value from the callback function is ignored. The **XCLASS_NOTIFICATION** transaction class consists of the following types:

* [XTYP_ADVSTOP](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advstop)
* [XTYP_CONNECT_CONFIRM](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-connect-confirm)
* [XTYP_DISCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-disconnect)
* [XTYP_ERROR](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-error)
* [XTYP_MONITOR](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-monitor)
* [XTYP_REGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-register)
* [XTYP_XACT_COMPLETE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-xact-complete)
* [XTYP_UNREGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-unregister)

The callback function is called asynchronously for transactions that do not involve the creation or termination of conversations. An application that does not frequently accept incoming messages will have reduced DDE performance because the Dynamic Data Exchange Management Library (DDEML) uses messages to initiate transactions.

An application must register the callback function by specifying a pointer to the function in a call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

## See also

**Conceptual**

[DdeEnableCallback](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeenablecallback)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)