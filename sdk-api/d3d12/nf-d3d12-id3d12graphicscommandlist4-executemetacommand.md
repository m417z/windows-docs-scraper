# ID3D12GraphicsCommandList4::ExecuteMetaCommand

## Description

Records the execution (or invocation) of the specified meta command into a graphics command list.

Call [ID3D12GraphicsCommandList4::InitializeMetaCommand](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-initializemetacommand) before executing a meta command. During invocation, you can specify overrides for values of any of the runtime parameters. You can execute multiple meta commands on the same graphics command list. And you can execute the same meta command multiple times on the same command list.

With a PIX capture taken with the use of meta commands, you can play that back on the same hardware configuration. But, by design, it's not portable to other GPUs.

## Parameters

### `pMetaCommand` [in]

A pointer to an **ID3D12MetaCommand** representing the meta command to initialize.

### `pExecutionParametersData` [in, optional]

An optional pointer to a constant structure containing the values of the parameters for executing the meta command.

### `ExecutionParametersDataSizeInBytes` [in]

A [SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) containing the size of the structure pointed to by *pExecutionParametersData*, if set, otherwise 0.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Your application is responsible for setting up the resources supplied to a meta command in the state required according to the meta command specification. The meta command definition specification defines the expected resource state for each parameter.
Your application is responsible for inserting unordered access view (UAV) barriers for input resources before the meta command's algorithm can consume them. You're also responsible for inserting the UAV barrier for the output resources when you intend to read them back.

During an algorithm invocation, the driver may insert as many UAV barriers to output resources as are needed to synchronize the output resource usage in the algorithm implementation. From your application's point of view, you should assume that all out and in/out resources are written to by the meta command, including scratch memory.

## See also

[ID3D12GraphicsCommandList4](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist4)