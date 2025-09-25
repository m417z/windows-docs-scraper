# AAAccountingDataType enumeration

## Description

Specifies the type of event that the [ITSGAccountingEngine::DoAccounting](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nf-tsgpolicyengine-itsgaccountingengine-doaccounting) method is being notified of.

## Constants

### `AA_MAIN_SESSION_CREATION:0`

A new session was created.

The following fields in the [AAAccountingData](https://learn.microsoft.com/windows/win32/api/tsgpolicyengine/ns-tsgpolicyengine-aaaccountingdata) structure represented by the *accountingData* parameter are valid:

* **userName**
* **clientName**
* **authType**
* **mainSessionId**

### `AA_SUB_SESSION_CREATION`

A new subsession was created by an existing connection.

The following fields in the [AAAccountingData](https://learn.microsoft.com/windows/win32/api/tsgpolicyengine/ns-tsgpolicyengine-aaaccountingdata) structure represented by the *accountingData* parameter are valid:

* **userName**
* **resourceName**
* **portNumber**
* **protocolName**
* **mainSessionId**
* **subSessionId**

### `AA_SUB_SESSION_CLOSED`

A subsession was closed.

The following fields in the [AAAccountingData](https://learn.microsoft.com/windows/win32/api/tsgpolicyengine/ns-tsgpolicyengine-aaaccountingdata) structure represented by the *accountingData* parameter are valid:

* **numberOfBytesTransfered**
* **numberOfBytesReceived**
* **mainSessionId**
* **subSessionId**

### `AA_MAIN_SESSION_CLOSED`

A connection was closed.

The following fields in the [AAAccountingData](https://learn.microsoft.com/windows/win32/api/tsgpolicyengine/ns-tsgpolicyengine-aaaccountingdata) structure represented by the *accountingData* parameter are valid:

* **mainSessionId**

## See also

[ITSGAccountingEngine::DoAccounting](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nf-tsgpolicyengine-itsgaccountingengine-doaccounting)