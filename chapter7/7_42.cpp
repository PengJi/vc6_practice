void ALGraph_DIJ(ALGraph G,int v0,Pathmatrix &P,ShortestPathTable &D){
	//在邻接表存储结构上实现迪杰斯特拉算法
	for(v=0;v<G.vexnum;v++)
		D[v]=INFINITY;
	for(p=G.vertices[v0].firstarc;p;p=p->nextarc)
		D[p->adjvex]=*p->info; 
	for(v=0;v<G.vexnum;v++){
		final[v]=0;
		for(w=0;w<G.vexnum;w++) 
			P[v][w]=0; 
		if(D[v]<INFINITY){
			P[v][v0]=1;
			P[v][v]=1;
		}
	}
	D[v0]=0;final[v0]=1;
	for(i=1;i<G.vexnum;i++){
		min=INFINITY;
		for(w=0;w<G.vexnum;w++)
			if(!final[w])
				if(D[w]<min){
					v=w;
					min=D[w];
				}
				final[v]=1;
				for(p=G.vertices[v].firstarc;p;p=p->nextarc){
					w=p->adjvex;
					if(!final[w]&&(min+(*p->info)<D[w])){
						D[w]=min+edgelen(G,v,w);
						P[w]=P[v];
						P[w][w]=1;
					}
				}
	}
}