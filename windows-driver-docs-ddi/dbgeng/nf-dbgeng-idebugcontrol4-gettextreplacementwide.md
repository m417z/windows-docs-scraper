# IDebugControl4::GetTextReplacementWide

## Description

The **GetTextReplacementWide** method returns the value of a user-named alias or an automatic alias.

## Parameters

### `SrcText` [in, optional]

Specifies the name of the alias. The engine first searches the user-named aliases for one with this name. Then, if no match is found, the automatic aliases are searched. If *SrcText* is **NULL**, *Index* is used to specify the alias.

### `Index` [in]

Specifies the index of an alias. The indexes of the user-named aliases come before the indexes of the automatic aliases. *Index* is only used if *SrcText* is **NULL**. *Index* can be used along with [GetNumberTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumbertextreplacements) to iterate over all the user-named and automatic aliases.

### `SrcBuffer` [out, optional]

Receives the name of the alias. This is the name specified in *SrcText*, if *SrcText* is not **NULL**. If *SrcBuffer* is **NULL**, this information is not returned.

### `SrcBufferSize` [in]

Specifies the size, in characters, of the *SrcBuffer* buffer.

### `SrcSize` [out, optional]

Receives the size, in characters, of the name of the alias. If *SrcSize* is **NULL**, this information is not returned.

### `DstBuffer` [out, optional]

Receives the value of the alias specified by *SrcText* and *Index*. If *DstBuffer* is **NULL**, this information is not returned.

### `DstBufferSize` [in]

Specifies the size, in characters, of the *DstBuffer* buffer.

### `DstSize` [out, optional]

Receives the size, in characters, of the value of the alias. If *DstSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Before executing commands or evaluating expressions, the debugger engine will replace the alias specified by *SrcBuffer* with the value of the alias (specified by *DstBuffer*).

For an overview of aliases used by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction), see [Using Aliases](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-aliases). For more information about using aliases with the debugger engine API, see [Interacting with the Engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/interacting-with-the-engine).

## See also

[GetNumberTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumbertextreplacements)

[GetTextMacro](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-gettextmacro)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)

[OutputTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputtextreplacements)

[SetTextReplacement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-settextreplacement)

[al (List Aliases)](https://learn.microsoft.com/windows-hardware/drivers/debugger/al--list-aliases-)