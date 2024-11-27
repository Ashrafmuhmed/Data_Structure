
class Node {
    constructor (data ,  next = null  ){
        this.next = next ; 
        this.data = data ;
    }
}
class Linkedlis{
    constructor(){
        this.head = null ; 
        this.size = 0 ;
    }

    // insert first node 
    insertFirst(value){
        this.head = new Node(value , this.head) ;
        this.size++ ;
    }

    // insert last element 
    insetLast(value){
        let node = new Node(value) ;
        if(this.isEmpty()) this.head = node ;
        else 
        {
            let current = this.head ;
            while(current.next){
                current = current.next ;
            }
            current.next = node ;
        }

        this.size++;
    }


    isEmpty(){
        return this.size > 0 ? false : true ;  
    }


    // insert at index
    insertAt(data , index){
        if(index > this.size || index < 0) throw ReferenceError ;
        else {
            const n = new Node(data) ;
            let bef = this.head ;
            for(let i = 1 ; i < index ; ++i) bef = bef.next ;
            n.next = bef.next ;
            bef.next = n ;
            this.size ++ ;
        }
        
    }


    // get at index
    getAt(index){
        if(index > this.size || index < 0) return undefined ;
        else {
            let c = 0 ;
            let cu = this.head ;
            for(let i = 0 ; i < index ; ++i)cu = cu.next ;
            return cu.data ;
        }
    }



    // remove at index 
    removeAt(index){
        if(index > this.size || index < 0) throw RangeError ;
        else {
            let cur = this.head ;
            for(let i = 1 ; i < index ; i++) cur = cur.next ;
            cur.next = cur.next.next ;
            this.size--;
        }
    }

    // print list data 
    printList(){
        let v = this.head ;
        while(v != null){
            console.log(v.data + " => ");
            v = v.next ;
        }
    }

    // clear List
    clearList(){
        this.head = null ;
    }
    } 


    const lK = new Linkedlis() ;
    console.log(lK.isEmpty());
    lK.insertFirst(555) ;
    lK.insertFirst(44) ;
    lK.insertFirst(455) ;
    lK.insetLast('ashraf');
    lK.insertFirst(45588) ;
    lK.insetLast(4558844) ;
    lK.printList();
    lK.insertAt(696969 , 1) ;
    console.log('============================================');
    lK.printList();
    console.log('============================================');
    lK.removeAt(1) ;
    lK.printList();
    lK.removeAt(5) ;
    console.log('============================================');
    lK.printList();

