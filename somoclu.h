/**
 * Self-Organizing Maps on a cluster
 *  Copyright (C) 2013 Peter Wittek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
 
float *loadCodebook(const char *mapFilename, 
                    unsigned int SOM_X, unsigned int SOM_Y, 
                    unsigned int NDIMEN);
int saveCodebook(char* cbFileName, float *codebook, 
                unsigned int SOM_X, unsigned int SOM_Y, unsigned int NDIMEN);
int saveUMat(char* fname, float *codebook, unsigned int nSomX, 
              unsigned int nSomY, unsigned int nDimensions);
void printMatrix(float *A, int nRows, int nCols);
float *readMatrix(const char *inFileName, 
                  unsigned int &nRows, unsigned int &nCols);
void train(int itask, float *data, unsigned int nSomX, unsigned int nSomY, 
           unsigned int nDimensions, unsigned int nVectors, 
           unsigned int nVectorsPerRank, unsigned int nEpoch, 
           const char *outPrefix, bool shouldSaveInterim, 
           unsigned int kernelType);
void trainOneEpochDenseCPU(int itask, float *data, float *numerator, 
                           float *denominator, float *codebook, 
                           unsigned int nSomX, unsigned int nSomY, 
                           unsigned int nDimensions, unsigned int nVectors,
                           unsigned int nVectorsPerRank, float radius);

extern "C" {
void setDevice(int commRank, int commSize);
void shutdownGpu();
void initializeGpu(float *hostData, int height, int width);
void trainOneEpochDenseGPU(int itask, float *data, float *numerator, 
                           float *denominator, float *codebook, 
                           unsigned int nSomX, unsigned int nSomY, 
                           unsigned int nDimensions, unsigned int nVectors,
                           unsigned int nVectorsPerRank, float radius);
void my_abort(int err);
}
