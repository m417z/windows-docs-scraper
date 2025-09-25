# COMPRESS_INFORMATION_CLASS enumeration

## Description

The values of this enumeration identify the type of information class being set or retrieved.

## Constants

### `COMPRESS_INFORMATION_CLASS_INVALID:0`

Invalid information class

### `COMPRESS_INFORMATION_CLASS_BLOCK_SIZE`

Customized block size. The value specified may be from 65536 to 67108864 bytes. This value can be used only with the LZMS compression algorithm. A minimum size of 1 MB is suggested to get a better compression ratio. An information class of this type is sizeof(DWORD).

### `COMPRESS_INFORMATION_CLASS_LEVEL`

Desired level of compression. The default value is **(DWORD)0**. The value **(DWORD)1** can improve the compression ratio with a slightly slower compression speed. This value can be used only with the XPRESS compression algorithm or the XPRESS with Huffman encoding compression algorithm. An information class of this type is sizeof(DWORD).