# WSMAN_DATA structure

## Description

Contains inbound and outbound data used in the Windows Remote Management (WinRM) API.

## Members

### `type`

Specifies the type of data currently stored in the union.

### `text`

### `binaryData`

### `number`

#### - ( unnamed union )

Contains the data.

#### text

If **type** is **WSMAN_DATA_TYPE_TEXT**, **text** contains a [WSMAN_DATA_TEXT](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data_text) structure.

#### binaryData

If **type** is **WSMAN_DATA_TYPE_XML_BINARY**, **binaryData** contains a [WSMAN_DATA_BINARY](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data_binary) structure.

#### number

If **type** is **WSMAN_DATA_TYPE_DWORD**, **number** is a DWORD integer.