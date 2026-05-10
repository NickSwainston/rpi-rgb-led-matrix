#include <stdint.h>
#include "pillow.h"

/* Minimal layout of Pillow's ImagingMemoryInstance, sufficient to reach
 * image32 without depending on the private Imaging.h header. The field
 * order and types match Pillow's struct exactly:
 *   mode/type/depth/bands/xsize/ysize  – six ints (24 bytes)
 *   palette                            – pointer  ( 8 bytes on 64-bit)
 *   image8                             – pointer  ( 8 bytes)
 *   image32                            – pointer  ( 8 bytes) ← target
 */
struct ImagingMemoryInstance {
    int mode;
    int type;
    int depth;
    int bands;
    int xsize;
    int ysize;
    void *palette;
    uint8_t **image8;
    int32_t **image32;
};

int** get_image32(void* im) {
    ImagingMemoryInstance* image = (ImagingMemoryInstance*) im;
    return image->image32;
}
