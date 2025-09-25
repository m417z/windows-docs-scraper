# AVIFileInit function

## Description

The **AVIFileInit** function initializes the AVIFile library.

The AVIFile library maintains a count of the number of times it is initialized, but not the number of times it was released. Use the [AVIFileExit](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifileexit) function to release the AVIFile library and decrement the reference count. Call **AVIFileInit** before using any other AVIFile functions.

This function supersedes the obsolete **AVIStreamInit** function.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)