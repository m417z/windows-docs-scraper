# AppPolicyClrCompat enumeration

## Description

The AppPolicyClrCompat enumeration indicates the application type of a process so that you can determine whether to enable private reflection and/or make managed objects agile.

## Constants

### `AppPolicyClrCompat_Other`

Indicates an application type other than the ones indicated by the other enumerated constants. The Common Language Runtime (CLR) should not be called by applications that are not Universal Windows Platform (UWP), Win32, nor Desktop Bridge.

### `AppPolicyClrCompat_ClassicDesktop`

Indicates a desktop/Win32 application, or an NT service. You can support private reflection on framework types.

### `AppPolicyClrCompat_Universal`

Indicates a Universal Windows Platform (UWP) application. You should disable private reflection on framework types, but you can support IAgileObject.

### `AppPolicyClrCompat_PackagedDesktop`

Indicates a Desktop Bridge application. You can support private reflection on framework types, and you can support IAgileObject.