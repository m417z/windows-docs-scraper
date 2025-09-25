# ISyncKnowledge2::GetInspector

## Description

Returns an object that can be used to retrieve the contents of the knowledge object.

## Parameters

### `riid` [in]

The IID of the requested inspector. Must be **IID_ICoreFragmentInspector**.

### `ppiInspector` [out]

An object that implements *riid*, and that can retrieve the contents of the knowledge object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOINTERFACE** | *riid* is not **IID_ICoreFragmentInspector**. |
| **E_POINTER** | Invalid pointer. |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)