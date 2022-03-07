
#define IMAGE_SIZE 10
int vis[10][10];
int cnt;
int val;
int tp[10][10];

// this function prints the array
void printImgArray(int array[IMAGE_SIZE][IMAGE_SIZE])
{
  
    printf("------ Image Contents -------\n");
    for (int i=0; i<IMAGE_SIZE; i++)
    {
    for (int j=0; j<IMAGE_SIZE; j++)
        printf("%2d, ",array[i][j]);
    printf("\n");
    }
    printf("-----------------------------\n");
}

/**
 * This function counts the number of distinct 
 * number (i.e. the number of cells)
 **/

void dfs(int i,int j,int image[IMAGE_SIZE][IMAGE_SIZE]){
    if(i<0 || i>=10 || j<0 || j>=10)return;
    vis[i][j]=1;
    tp[i][j]=val;

    if(image[i+1][j]==1 && vis[i+1][j]==0)dfs(i+1,j,image);
    if(image[i-1][j]==1 && vis[i-1][j]==0)dfs(i-1,j,image);
    if(image[i][j-1]==1 && vis[i][j-1]==0)dfs(i,j-1,image);
    if(image[i][j+1]==1 && vis[i][j+1]==0)dfs(i,j+1,image);
    if(image[i+1][j+1]==1 && vis[i+1][j+1]==0)dfs(i+1,j+1,image);
    if(image[i+1][j-1]==1 && vis[i+1][j-1]==0)dfs(i+1,j-1,image);
    if(image[i-1][j+1]==1 && vis[i-1][j+1]==0)dfs(i-1,j+1,image);
    if(image[i-1][j-1]==1 && vis[i-1][j-1]==0)dfs(i-1,j-1,image);
}


int cellCount(int image[IMAGE_SIZE][IMAGE_SIZE]){
    // insert your code for task1.1 here
    // you may want to change the return value. 
    cnt=0;
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)vis[i][j]=0;
    for (int i=0; i<IMAGE_SIZE; i++)
    {
          for (int j=0; j<IMAGE_SIZE; j++)
              {
                    
                if(image[i][j]==1 && vis[i][j]==0){
                    dfs(i,j,image);
                    cnt++;
                }


              }     
    }




    return cnt;
}
/** 
 * This function colors each cell with a unique color
 * (i.e. unique number)
 **/
void color(int image[IMAGE_SIZE][IMAGE_SIZE]){
    // insert your code for task 1.2 here
	val=1;
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)vis[i][j]=0,tp[i][j]=0;
    for (int i=0; i<IMAGE_SIZE; i++)
    {
          for (int j=0; j<IMAGE_SIZE; j++)
              {
                    
                if(image[i][j]==1 && vis[i][j]==0){
                    dfs(i,j,image);
                    
                    val++;
                    
                }


              }     
    }
}

/**
 * This function colors each cell with a unique color
 * (i.e., unique number). This function works with 
 * pointers
 * currentRow: shows the current row that is processed
 * currentCol: shows the current column that is process
 * currentIndex: show the index that is processed
 * color: is an integer that represents a color
 **/

int colorRecursively(int image[IMAGE_SIZE][IMAGE_SIZE], int currentRow, int currentCol, int currentIndex, int color) {
    // insert your code for task 2.1 here, in case you decided to complete this task
    // you may want to change the return value
    return 0;
 
}
void colorPtr(int* image){
    // insert your code for task 2.2 here

}
 

#ifndef __testing
int main(){

    // DO not change anything in main(), it will confuse the
    // auto-checker.  
    puts("testing the code with color() function");
    int count = 0;
    int cellImg[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};

    printImgArray(cellImg);
    color(cellImg);
    printImgArray(cellImg);
    count=cellCount(cellImg);
    printf("Total number of cells in the image: %d\n",count);
 

    puts("Testing the code with colorPtr");
    int cellImg_[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};

    int* ptr = cellImg_;
    printImgArray(ptr);
    colorPtr(ptr);
    printImgArray(ptr);
    count=cellCount(ptr);
    printf("Total number of cells in the image: %d\n",count); 
    puts("Testing the code with colorRecursively");
    int cellImg__[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};
    printImgArray(cellImg__);
    colorRecursively(cellImg__, 0, 0, 1, 0);
    printImgArray(tp);
    printf("\n");
    
    for(int i=0;i<10;i++){
    	for(int j=0;j<10;j++){
    		printf("\n",tp[i][j]);
		}
		printf("\n");
	}
    count=cellCount(cellImg__);
    printf("Total number of cells in the image: %d\n",count);
    return 0;
}
#endif