typedef enum ThumbnailStreamCacheOptions {
  ExtractIfNotCached = 0,
  ReturnOnlyIfCached = 0x1,
  ResizeThumbnail = 0x2,
  AllowSmallerSize = 0x4
} ;