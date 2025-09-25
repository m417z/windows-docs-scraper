# D3D12DDI_PREDICATION_OP enumeration

## Description

Contains values for predication operation options. This method is used to denote that subsequent video operations and resource manipulation commands are not actually performed if the resulting predicate data of the predicate is equal to the operation specified.

## Constants

### `D3D12DDI_PREDICATION_OP_EQUAL_ZERO`

Enables predication if all the bits in a 64 bit buffer are zero (0).

### `D3D12DDI_PREDICATION_OP_NOT_EQUAL_ZERO`

Enables predication if at least one of the 64 bit buffer are not zero (0).

## Remarks

Predication enables the caller to have an if statement in the command buffer. ID3D12*CommandList::SetPredication command marks the beginning of the if statement. The if statement ends at the next call to ID3D12*CommandList::SetPredication or when the command list is closed. Also, predication doesn’t support nested if’s, else-if, or else. The expression to evaluate for the if is passed as parameters to the ID3D12*CommandList::SetPredication call. A pointer to a 64bit value is passed in as a D3D12 buffer and a 64bit aligned byte offset. The operation specifies the comparison.

If the expression evaluates to true, the commands in the if-statement are *not* executed.

The value itself is only determined once the SetPredication command executes on the GPU. The value of the buffer must be “captured” by the SetPredication command when executed on the GPU, such that subsequent modifications to the buffer don’t change whether or not the commands in the if statement are executed. The value stored in the buffer could be from anywhere. Examples are the decode query statistics Status value, a value written by a shader, etc.

Within a command list, applications can call ID3D12*CommandList::SetPredication with a null resource pointer to disable predication for subsequent commands in the command list. Otherwise the predication state is reset to disabled when the user closes and resets the command list for execution, so the SetPredication is not retained across command lists.