# InitializeXamlDiagnosticsEx function

## Description

Initializes a Xaml Diagnostics session. This is the entry point for any debugging tool using the XAML Diagnostic APIs.

## Parameters

### `endPointName` [in]

The end point name for Visual Diagnostics.

### `pid` [in]

The pid of the process to connect to.

### `wszDllXamlDiagnostics` [in]

The path to XamlDiagnostics.dll.

### `wszTAPDllName` [in]

The name of the DLL to be injected in the process.

### `tapClsid` [in]

The COM CLSID of an object implementing IObjectWithSite, to be created from the DLL to be injected in the process. The site object will implement IXamlDiagnostics.

### `wszInitializationData` [in]

Initialization data for Xaml Diagnostics.