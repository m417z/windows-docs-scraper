## Description

Compiles Microsoft High Level Shader Language (HLSL) code into bytecode for a given target.

## Parameters

### `pSrcData` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to uncompiled shader data (ASCII HLSL code).

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of the block of memory that *pSrcData* points to.

### `pSourceName` [in, optional]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An optional pointer to a constant null-terminated string containing the name that identifies the source data to use in error messages. If not used, set to **NULL**.

### `pDefines` [in, optional]

Type: **const [D3D_SHADER_MACRO](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)***

An optional array of [D3D_SHADER_MACRO](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro) structures that define shader macros. Each macro definition contains a name and a null-terminated definition. If not used, set to **NULL**. The last structure in the array serves as a terminator and must have all members set to **NULL**.

### `pInclude` [in, optional]

Type: **[ID3DInclude](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3dinclude)***

A pointer to an [ID3DInclude](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3dinclude) interface that the compiler uses to handle include files. If you set this parameter to **NULL** and the shader contains a #include, a compile error occurs. You can pass the **D3D_COMPILE_STANDARD_FILE_INCLUDE** macro, which is a pointer to a default include handler. This default include handler includes files that are relative to the current directory and files that are relative to the directory of the initial source file. When you use **D3D_COMPILE_STANDARD_FILE_INCLUDE**, you must specify the source file name in the *pSourceName* parameter; the compiler will derive the initial relative directory from *pSourceName*.

```
#define D3D_COMPILE_STANDARD_FILE_INCLUDE ((ID3DInclude*)(UINT_PTR)1)
```

### `pEntrypoint` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a constant null-terminated string that contains the name of the shader entry point function where shader execution begins. When you compile an effect, **D3DCompile2** ignores *pEntrypoint*; we recommend that you set *pEntrypoint* to **NULL** because it is good programming practice to set a pointer parameter to **NULL** if the called function will not use it.

### `pTarget` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a constant null-terminated string that specifies the shader target or set of shader features to compile against. The shader target can be a shader model (for example, shader model 2, shader model 3, shader model 4, or shader model 5). The target can also be an effect type (for example, fx_4_1). For info about the targets that various profiles support, see [Specifying Compiler Targets](https://learn.microsoft.com/windows/desktop/direct3dhlsl/specifying-compiler-targets).

### `Flags1` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of shader [D3D compile constants](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-constants) that are combined by using a bitwise **OR** operation. The resulting value specifies how the compiler compiles the HLSL code.

### `Flags2` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of effect [D3D compile effect constants](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-effect-constants) that are combined by using a bitwise **OR** operation. The resulting value specifies how the compiler compiles the effect. When you compile a shader and not an effect file, **D3DCompile2** ignores *Flags2*; we recommend that you set *Flags2* to zero because it is good programming practice to set a nonpointer parameter to zero if the called function will not use it.

### `SecondaryDataFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of the following flags that are combined by using a bitwise **OR** operation. The resulting value specifies how the compiler compiles the HLSL code.

| Flag | Description |
| --- | --- |
| D3DCOMPILE_SECDATA_MERGE_UAV_SLOTS (0x01) | Merge unordered access view (UAV) slots in the secondary data that the *pSecondaryData* parameter points to. |
| D3DCOMPILE_SECDATA_PRESERVE_TEMPLATE_SLOTS (0x02) | Preserve template slots in the secondary data that the *pSecondaryData* parameter points to. |
| D3DCOMPILE_SECDATA_REQUIRE_TEMPLATE_MATCH (0x04) | Require that templates in the secondary data that the *pSecondaryData* parameter points to match when the compiler compiles the HLSL code. |

If *pSecondaryData* is **NULL**, set to zero.

### `pSecondaryData` [in, optional]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to secondary data. If you don't pass secondary data, set to **NULL**. Use this secondary data to align UAV slots in two shaders. Suppose shader A has UAVs and they are bound to some slots. To compile shader B such that UAVs with the same names are mapped in B to the same slots as in A, pass A’s byte code to **D3DCompile2** as the secondary data.

### `SecondaryDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of the block of memory that *pSecondaryData* points to. If *pSecondaryData* is **NULL**, set to zero.

### `ppCode` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a variable that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access the compiled code.

### `ppErrorMsgs` [out, optional]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a variable that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access compiler error messages, or **NULL** if there are no errors.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The difference between **D3DCompile2** and [D3DCompile](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile) is that **D3DCompile2** takes some optional parameters (*SecondaryDataFlags*, *pSecondaryData* and *SecondaryDataSize*) that can be used to control some aspects of how bytecode is generated. Refer to the descriptions of these parameters for more details. There is no difference otherwise to the efficiency of the bytecode generated between **D3DCompile2** and **D3DCompile**.

### Compiling shaders for UWP

To compile offline shaders the recommended approach is to use the [Effect-compiler tool](https://learn.microsoft.com/windows/desktop/direct3dtools/fxc). If you can't compile all of your shaders ahead of time, then consider compiling the more expensive ones and the ones that your startup and most performance-sensitive paths require, and compiling the rest at runtime. You can use a process similar to the following to compile a loaded or generated shader in a UWP application without blocking your user interface thread.

* Using Visual Studio 2015+ to develop the UWP app, add the new item "shader.hlsl".
   * In the **Solution Folder** view of Visual Studio, select the **shaders.hlsl**  item, right-click for **Properties**.
   * Make sure the item **Content** is set to **Yes**.
   * Make sure the **Item Type** is set to **Text**.
   * Add a button to XAML, name it appropriately ("TheButton" in this example), and add a **Click** handler.
* Now add these includes to your .cpp file:

``` syntax
   #include <ppltasks.h>
   #include <d3dcompiler.h>
   #include <Robuffer.h>
   ```

* Use the following code to call **D3DCompile2**. Note that there's no error checking or handling here, and also that this code demonstrates that you can do both I/O and compilation in the background, which leaves your UI more responsive.

```cppcx
void App1::DirectXPage::TheButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
  std::shared_ptr<Microsoft::WRL::ComPtr<ID3DBlob>> blobRef = std::make_shared<Microsoft::WRL::ComPtr<ID3DBlob>>();

  // Load a file and compile it.
  auto fileOp = Windows::ApplicationModel::Package::Current->InstalledLocation->GetFileAsync(L"shader.hlsl");
  create_task(fileOp).then([this](Windows::Storage::StorageFile^ file) -> IAsyncOperation<Windows::Storage::Streams::IBuffer^>^
  {
    // Do file I/O in background thread (use_arbitrary).
    return Windows::Storage::FileIO::ReadBufferAsync(file);
  }, task_continuation_context::use_arbitrary())
    .then([this, blobRef](Windows::Storage::Streams::IBuffer^ buffer)
  {
    // Do compilation in background thread (use_arbitrary).

    // Cast to Object^, then to its underlying IInspectable interface.
    Microsoft::WRL::ComPtr<IInspectable> insp(reinterpret_cast<IInspectable*>(buffer));

    // Query the IBufferByteAccess interface.
    Microsoft::WRL::ComPtr<Windows::Storage::Streams::IBufferByteAccess> bufferByteAccess;
    insp.As(&bufferByteAccess);

    // Retrieve the buffer data.
    byte *pBytes = nullptr;
    bufferByteAccess->Buffer(&pBytes);

    Microsoft::WRL::ComPtr<ID3DBlob> blob;
    Microsoft::WRL::ComPtr<ID3DBlob> errMsgs;
    D3DCompile2(pBytes, buffer->Length, "shader.hlsl", nullptr, nullptr, "main", "ps_5_0", 0, 0, 0, nullptr, 0, blob.GetAddressOf(), errMsgs.GetAddressOf());
    *blobRef = blob;
  }, task_continuation_context::use_arbitrary())
    .then([this, blobRef]()
  {
    // Update UI / use shader on foreground thread.
    wchar_t message[40];
    swprintf_s(message, L"blob is %u bytes long", (unsigned)(*blobRef)->GetBufferSize());
    this->TheButton->Content = ref new Platform::String(message);
  }, task_continuation_context::use_current());
}
```

## See also

* [Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)
* [Specifying D3D12 Root Signatures in HLSL](https://learn.microsoft.com/windows/desktop/direct3d12/specifying-root-signatures-in-hlsl)