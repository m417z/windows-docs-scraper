# ID3D11DeviceContext::Dispatch

## Description

Execute a command list from a thread group.

## Parameters

### `ThreadGroupCountX` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of groups dispatched in the x direction. *ThreadGroupCountX* must be less than or equal to D3D11_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION (65535).

### `ThreadGroupCountY` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of groups dispatched in the y direction. *ThreadGroupCountY* must be less than or equal to D3D11_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION (65535).

### `ThreadGroupCountZ` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of groups dispatched in the z direction. *ThreadGroupCountZ* must be less than or equal to D3D11_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION (65535).
In feature level 10 the value for *ThreadGroupCountZ* must be 1.

## Remarks

You call the **Dispatch** method to execute commands in a [compute shader](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-compute-shader). A compute shader can be run on many threads in parallel, within a thread group. Index a particular thread, within a thread group using a 3D vector
given by (x,y,z).

In the following illustration, assume a thread group with 50 threads where the size of the group is given by (5,5,2). A single thread is identified from a
thread group with 50 threads in it, using the vector (4,1,1).

![Illustration of a single thread within a thread group of 50 threads](https://learn.microsoft.com/windows/win32/api/d3d11/images/d3d11_thread_group_1.png)

The following illustration shows the relationship between the parameters passed to **ID3D11DeviceContext::Dispatch**, Dispatch(5,3,2), the values specified in the [numthreads](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-attributes-numthreads) attribute, numthreads(10,8,3), and values that will passed to the compute shader for the thread-related system values
([SV_GroupIndex](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff471569(v=vs.85)),[SV_DispatchThreadID](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sv-dispatchthreadid),[SV_GroupThreadID](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sv-groupthreadid),[SV_GroupID](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sv-groupid)).

![Illustration of the relationship between Dispatch, thread groups, and threads](https://learn.microsoft.com/windows/win32/api/d3d11/images/ThreadGroupIDs.png)

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)