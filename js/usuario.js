ingresar = document.getElementById("boton")

boton.addEventListener("click",function(){

    let usuario = document.getElementById("user").value // variable que toma valor del campo email
    let contrasena = document.getElementById("contra").value // variable que toma valor del campo contraseña
    
    entrar()
    /* if(usuario == valor && contrasena ==valor1 ){
        entrar()
        localStorage.setItem("usuario",usuario);
    } */
})
function entrar(){
    window.location = "principal.html"
}