# GetEnabledXStateFeatures function

## Description

Gets a mask of enabled XState features on x86 or x64 processors.

The definition of XState feature bits are processor vendor specific. Please refer to the relevant processor
reference manuals for additional information on a particular feature.

## Return value

This function returns a bitmask in which each bit represents an XState feature that is enabled on the
system.

## Remarks

An application should call this function to determine what features are present and enabled on the system
before using an XState processor feature or attempting to manipulate XState contexts. Bits 0 and 1 refer to the
X87 FPU and the presence of SSE registers, respectively. The meanings of specific feature bits beyond 0 and 1 are
defined in the Programmer Reference Manuals released by the processor vendors.

**Note** Not all features supported by a processor may be enabled on the system. Using a feature which is not
enabled may result in exceptions or undefined behavior.

**Windows 7 with SP1 and Windows Server 2008 R2 with SP1:** The [AVX API](https://learn.microsoft.com/windows/desktop/Debug/avx-support-portal) is first implemented on
Windows 7 with SP1 and Windows Server 2008 R2 with SP1 . Since there is no SDK for SP1, that means there are
no available headers and library files to work with. In this situation, a caller must declare the needed
functions from this documentation and get pointers to them using
[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea) on
"Kernel32.dll", followed by calls to
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). See
[Working with XState Context](https://learn.microsoft.com/windows/desktop/Debug/working-with-xstate-context) for
details.

## See also

[Intel AVX](https://learn.microsoft.com/windows/desktop/Debug/avx-support-portal)

[Working with XState Context](https://learn.microsoft.com/windows/desktop/Debug/working-with-xstate-context)