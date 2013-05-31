#include <vips/vips>

using namespace vips;

int
main (int argc, char **argv)
{
    try {
        // open the file named in argv[1] ... can be TIFF, JPEG,
        // PBM/PGM/PPM, PNG, HDR, Matlab or VIPS format
        // if libMagick was found when VIPS was built, this will
        // also load any libMagick-supported image format (more than 80)
        VImage fred (argv[1]);
              
        // make a 3x3 sharpen mask
        VIMask sharp (3, 3, 8, 0,
            -1, -1, -1,
            -1, 16, -1,
            -1, -1, -1);
              
        // brighten and sharpen
        VImage jim = (fred * 1.2).conv (sharp);
                            
        // write to file argv[2]
        jim.write (argv[2]);
    }
    catch (VError &e) {
        e.perror (argv[0]);
    }
            
    return (0);
}