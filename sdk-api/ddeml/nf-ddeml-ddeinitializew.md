# DdeInitializeW function

## Description

Registers an application with the [Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library) (DDEML). An application must call this function before calling any other Dynamic Data Exchange Management Library (DDEML) function.

## Parameters

### `pidInst` [in, out]

Type: **LPDWORD**

The application instance identifier. At initialization, this parameter should point to 0. If the function succeeds, this parameter points to the instance identifier for the application. This value should be passed as the
*idInst* parameter in all other DDEML functions that require it. If an application uses multiple instances of the DDEML dynamic-link library (DLL), the application should provide a different callback function for each instance.

If
*pidInst* points to a nonzero value, reinitialization of the DDEML is implied. In this case,
*pidInst* must point to a valid application-instance identifier.

### `pfnCallback` [in]

Type: **PFNCALLBACK**

A pointer to the application-defined DDE callback function. This function processes DDE transactions sent by the system. For more information, see the [DdeCallback](https://learn.microsoft.com/windows/desktop/api/ddeml/nc-ddeml-pfncallback) callback function.

### `afCmd` [in]

Type: **DWORD**

A set of **APPCMD_**, **CBF_**, and **MF_** flags. The **APPCMD_** flags provide special instructions to **DdeInitialize**. The **CBF_** flags specify filters that prevent specific types of transactions from reaching the callback function. The **MF_** flags specify the types of DDE activity that a DDE monitoring application monitors. Using these flags enhances the performance of a DDE application by eliminating unnecessary calls to the callback function.

This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **APPCLASS_MONITOR**<br><br>0x00000001L | Makes it possible for the application to monitor DDE activity in the system. This flag is for use by DDE monitoring applications. The application specifies the types of DDE activity to monitor by combining one or more monitor flags with the **APPCLASS_MONITOR** flag. For details, see the following Remarks section. |
| **APPCLASS_STANDARD**<br><br>0x00000000L | Registers the application as a standard (nonmonitoring) DDEML application. |
| **APPCMD_CLIENTONLY**<br><br>0x00000010L | Prevents the application from becoming a server in a DDE conversation. The application can only be a client. This flag reduces consumption of resources by the DDEML. It includes the functionality of the **CBF_FAIL_ALLSVRXACTIONS** flag. |
| **APPCMD_FILTERINITS**<br><br>0x00000020L | Prevents the DDEML from sending [XTYP_CONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-connect) and [XTYP_WILDCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-wildconnect) transactions to the application until the application has created its string handles and registered its service names or has turned off filtering by a subsequent call to the [DdeNameService](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddenameservice) or **DdeInitialize** function. This flag is always in effect when an application calls **DdeInitialize** for the first time, regardless of whether the application specifies the flag. On subsequent calls to **DdeInitialize**, not specifying this flag turns off the application's service-name filters, but specifying it turns on the application's service name filters. |
| **CBF_FAIL_ALLSVRXACTIONS**<br><br>0x0003f000 | Prevents the callback function from receiving server transactions. The system returns **DDE_FNOTPROCESSED** to each client that sends a transaction to this application. This flag is equivalent to combining all CBF_FAIL_ flags. |
| **CBF_FAIL_ADVISES**<br><br>0x00004000 | Prevents the callback function from receiving [XTYP_ADVSTART](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advstart) and [XTYP_ADVSTOP](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advstop) transactions. The system returns **DDE_FNOTPROCESSED** to each client that sends an **XTYP_ADVSTART** or **XTYP_ADVSTOP** transaction to the server. |
| **CBF_FAIL_CONNECTIONS**<br><br>0x00002000 | Prevents the callback function from receiving [XTYP_CONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-connect) and [XTYP_WILDCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-wildconnect) transactions. |
| **CBF_FAIL_EXECUTES**<br><br>0x00008000 | Prevents the callback function from receiving [XTYP_EXECUTE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-execute) transactions. The system returns **DDE_FNOTPROCESSED** to a client that sends an **XTYP_EXECUTE** transaction to the server. |
| **CBF_FAIL_POKES**<br><br>0x00010000 | Prevents the callback function from receiving [XTYP_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-poke) transactions. The system returns **DDE_FNOTPROCESSED** to a client that sends an **XTYP_POKE** transaction to the server. |
| **CBF_FAIL_REQUESTS**<br><br>0x00020000 | Prevents the callback function from receiving [XTYP_REQUEST](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-request) transactions. The system returns **DDE_FNOTPROCESSED** to a client that sends an **XTYP_REQUEST** transaction to the server. |
| **CBF_FAIL_SELFCONNECTIONS**<br><br>0x00001000 | Prevents the callback function from receiving [XTYP_CONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-connect) transactions from the application's own instance. This flag prevents an application from establishing a DDE conversation with its own instance. An application should use this flag if it needs to communicate with other instances of itself but not with itself. |
| **CBF_SKIP_ALLNOTIFICATIONS**<br><br>0x003c0000 | Prevents the callback function from receiving any notifications. This flag is equivalent to combining all CBF_SKIP_ flags. |
| **CBF_SKIP_CONNECT_CONFIRMS**<br><br>0x00040000 | Prevents the callback function from receiving [XTYP_CONNECT_CONFIRM](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-connect-confirm) notifications. |
| **CBF_SKIP_DISCONNECTS**<br><br>0x00200000 | Prevents the callback function from receiving [XTYP_DISCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-disconnect) notifications. |
| **CBF_SKIP_REGISTRATIONS**<br><br>0x00080000 | Prevents the callback function from receiving [XTYP_REGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-register) notifications. |
| **CBF_SKIP_UNREGISTRATIONS**<br><br>0x00100000 | Prevents the callback function from receiving [XTYP_UNREGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-unregister) notifications. |
| **MF_CALLBACKS**<br><br>0x08000000 | Notifies the callback function whenever a transaction is sent to any DDE callback function in the system. |
| **MF_CONV**<br><br>0x40000000 | Notifies the callback function whenever a conversation is established or terminated. |
| **MF_ERRORS**<br><br>0x10000000 | Notifies the callback function whenever a DDE error occurs. |
| **MF_HSZ_INFO**<br><br>0x01000000 | Notifies the callback function whenever a DDE application creates, frees, or increments the usage count of a string handle or whenever a string handle is freed as a result of a call to the [DdeUninitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeuninitialize) function. |
| **MF_LINKS**<br><br>0x20000000 | Notifies the callback function whenever an advise loop is started or ended. |
| **MF_POSTMSGS**<br><br>0x04000000 | Notifies the callback function whenever the system or an application posts a DDE message. |
| **MF_SENDMSGS**<br><br>0x02000000 | Notifies the callback function whenever the system or an application sends a DDE message. |

### `ulRes`

Type: **DWORD**

Reserved; must be set to zero.

## Return value

Type: **UINT**

If the function succeeds, the return value is **DMLERR_NO_ERROR**.

If the function fails, the return value is one of the following values:

## Remarks

An application that uses multiple instances of the DDEML must not pass DDEML objects between instances.

A DDE monitoring application should not attempt to perform DDE operations (establish conversations, issue transactions, and so on) within the context of the same application instance.

A synchronous transaction fails with a **DMLERR_REENTRANCY** error if any instance of the same task has a synchronous transaction already in progress.

The **CBF_FAIL_ALLSVRXACTIONS** flag causes the DDEML to filter all server transactions and can be changed by a subsequent call to **DdeInitialize**. The **APPCMD_CLIENTONLY** flag prevents the DDEML from creating key resources for the server and cannot be changed by a subsequent call to **DdeInitialize**.

There is an ANSI version and a Unicode version of **DdeInitialize**. The version called determines the type of the window procedures used to control DDE conversations (ANSI or Unicode), and the default value for the
*iCodePage* member of the
[CONVCONTEXT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convcontext) structure (**CP_WINANSI** or **CP_WINUNICODE**).

> [!NOTE]
> The ddeml.h header defines DdeInitialize as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Dynamic Data Exchange Management Library Overview](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)