# D3D12_DISPATCH_ARGUMENTS structure

## Description

Describes dispatch parameters, for use by the compute shader.

## Members

### `ThreadGroupCountX`

The size, in thread groups, of the x-dimension of the thread-group grid.

### `ThreadGroupCountY`

The size, in thread groups, of the y-dimension of the thread-group grid.

### `ThreadGroupCountZ`

The size, in thread groups, of the z-dimension of the thread-group grid.

## Remarks

The members of this structure serve the same purpose as the parameters of [Dispatch](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-dispatch).

 A compiled compute shader defines the set of instructions to execute per thread and the number of threads to run per group. The thread-group parameters indicate how many thread groups to execute. Each thread group contains the same number of threads, as defined by the compiled compute shader. The thread groups are organized in a three-dimensional grid. The total number of thread groups that the compiled compute shader executes is determined by the following calculation:

``` syntax
ThreadGroupCountX * ThreadGroupCountY * ThreadGroupCountZ
```

In particular, if any of the values in the thread-group parameters are 0, nothing will happen.

The maximum size of any dimension is 65535.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)