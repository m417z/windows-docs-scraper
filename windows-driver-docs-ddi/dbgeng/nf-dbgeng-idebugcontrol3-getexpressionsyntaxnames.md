# IDebugControl3::GetExpressionSyntaxNames

## Description

The **GetExpressionSyntaxNames** method returns the full and abbreviated names of an expression syntax.

## Parameters

### `Index` [in]

Specifies the index of the expression syntax. *Index* should be between zero and the number of expression syntaxes returned by [GetNumberExpressionSyntaxes](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumberexpressionsyntaxes) minus one.

### `FullNameBuffer` [out, optional]

Receives the full name of the expression syntax. If *FullNameBuffer* is **NULL**, this information is not returned.

### `FullNameBufferSize` [in]

Specifies the size, in characters, of the buffer *FullNameBuffer*. This size includes the space for the '\0' terminating character.

### `FullNameSize` [out, optional]

Receives the size, in characters, of the full name of the expression syntax. This size includes the space for the '\0' terminating character. If *FullNameSize* is **NULL**, this information is not returned.

### `AbbrevNameBuffer` [out, optional]

Receives the abbreviated name of the expression syntax. This size includes the space for the '\0' terminating character. If *AbbrevNameBuffer* is **NULL**, this information is not returned.

### `AbbrevNameBufferSize` [in]

Specifies the size, in characters, of the buffer *AbbrevNameBufferSize*. This size includes the space for the '\0' terminating character.

### `AbbrevNameSize` [out, optional]

Receives the size, in characters, of the abbreviated name of the expression syntax. This size includes the space for the '\0' terminating character. If *AbbrevNameSize* is **NULL**, this information is not returned.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, either *FullNameBufferSize* or *AbbrevNameBufferSize* was smaller than the size of the respective expression syntax name, and the name was truncated to fit inside the buffer. |

## Remarks

Currently, there are two expression syntaxes, their full names are "Microsoft Assembler expressions" and "C++ source expressions." The corresponding abbreviated expression syntaxes are "MASM" and "C++."

## See also

[Evaluate](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-evaluate)

[GetNumberExpressionSyntaxes](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumberexpressionsyntaxes)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetExpressionSyntaxByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexpressionsyntaxbyname)